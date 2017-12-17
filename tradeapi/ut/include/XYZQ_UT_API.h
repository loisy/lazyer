// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the XYZQ_UT_API_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// XYZQ_UT_API_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef XYZQ_UT_API_EXPORTS
#define XYZQ_UT_API __declspec(dllexport)
#else
#define XYZQ_UT_API __declspec(dllimport)
#endif

#pragma once

#include "xyzq_ut_datatype.h"
#include "XYZQ_UT_constant.h"
#include <string.h>

// 以下是C接口，对速度有较高要求的用户可以选用
#ifdef __cplusplus
extern "C" {
#endif
	//注册登录地址
	int XYZQ_UT_API WINAPI ut_register_address(char* address);

	//注册回调函数
	int XYZQ_UT_API WINAPI ut_register_spi(xyzq_ut_c_spi spi);

	//初始化
	void XYZQ_UT_API WINAPI ut_init();

	//登录认证
	int XYZQ_UT_API WINAPI ut_authorize(const char* account, const char* username, const char* password);

    //取连接状态
    BOOL XYZQ_UT_API WINAPI ut_isconnected();

	//登出
	int XYZQ_UT_API WINAPI ut_logout();
    
    int XYZQ_UT_API WINAPI ut_release();

    //重登录
    int XYZQ_UT_API WINAPI ut_relogin();

    //修改密码
	int XYZQ_UT_API WINAPI ut_change_password(const char* account, const char* username, const char* oldpassword, const char* newpassword);

    //订阅
    int XYZQ_UT_API WINAPI ut_subscribe(sub_item_c* sitem);  // 单品种订阅
    int XYZQ_UT_API WINAPI ut_subscribe_multi(int code_count, ut_code_string* codes, sub_fields_c* fields);  // 多品种相同字段订阅
    int XYZQ_UT_API WINAPI ut_subscribe_multi_ex(int code_count, sub_item_c* plist[]);  // 多品种不同字段订阅
    
    //订阅逐笔数据
    int XYZQ_UT_API WINAPI ut_subscribe_transactions(int code_count, ut_code_string* codes);

    //订阅挂单数据，暂未开放
    //int XYZQ_UT_API WINAPI ut_subscribe_orders(code_list* codes);
    //int XYZQ_UT_API WINAPI ut_subscribe_order_queues(code_list* codes);
	
    //获得快照
	int XYZQ_UT_API WINAPI ut_get_snapshot(int code_count, sub_item_c* plist[]);
	
    //获得证券基础信息
	//int XYZQ_UT_API WINAPI ut_get_baseinfo(base_info_req *bir);
	
    //退订
	int XYZQ_UT_API WINAPI ut_unsubscribe(int sub_type, int code_count, ut_code_string* codes);
    int XYZQ_UT_API WINAPI ut_unsubscribe_all(int sub_type);

    //设置/获取用户参数
    int XYZQ_UT_API WINAPI ut_set_config(int config_item, int value);
    int XYZQ_UT_API WINAPI ut_get_config(int config_item, int* value);

#ifdef __cplusplus
};
#endif

// 以下是C++接口
#ifdef __cplusplus

class xyzq_ut_spi abstract
{
public:

	//错误信息响应
    virtual void rsp_error(error_msg *arg) {};
	//状态响应
    virtual void rsp_status_changed(int status) {};
	//单个品种行情推送
    virtual void rsp_market_data(ut_data *arg) {};
	//单个品种逐笔成交推送
    virtual void rsp_transactions(ut_data *arg) {};
    //单个品种逐笔委托推送
    virtual void rsp_orders(ut_data *arg) {};
	//单个品种委托队列推送
    virtual void rsp_order_list(ut_data *arg) {};
	//查询基础信息响应
    virtual void rsp_base_info(rsp_base_info_s *arg) {};
};

class xyzq_ut_api
{
public:
	//生成api
	static xyzq_ut_api *create_ut_api()
    {
        static xyzq_ut_api instance;
        return &instance;
    };

	//注册登录地址
	int register_address(char* address)
    {
        return ut_register_address(address);
    }

	//注册回调类
	int register_spi(xyzq_ut_spi *spi)
    {
        custom_spi(spi);
        return ut_register_spi(virtual_callback);
    }

	//初始化
	void init()
    {
        return ut_init();
    }

	//登录认证
	int authorize(authorize_struct *as)
    {
        return ut_authorize(as->account_no.c_str(), as->username.c_str(), as->password.c_str());
    }

    //取连接状态
    bool isconnected()
    {
        return ut_isconnected();
    }

	//登出
	int logout()
    {
        return ut_logout();
    }
    
    //重登录
    int relogin()
    {
        return ut_relogin();
    }

    //修改密码
	int change_password(change_pwd *cp)
    {
        return ut_change_password(  cp->account_no.c_str(), 
                                    cp->username.c_str(), 
                                    cp->oldpassword.c_str(),
                                    cp->newpassword.c_str() );
    }

	//订阅

    // 单品种订阅
    int subscribe(sub_item_c* sitem)
    {
        return ut_subscribe(sitem);
    }

    // 单品种订阅
    int subscribe(sub_item* sitem)
    {
        if (!sitem)
            return XYUT_ERR_BAD_API_PARAMETERS;
        int n = sitem->fields.size();
        sub_item_c* citem = (sub_item_c*) malloc(sizeof(sub_item_c) + (n-1)*sizeof(int));
        citem->fields.count = n;
        memcpy(citem->fields.fields, &sitem->fields[0], sizeof(int) * n);
        strcpy_s(citem->code, max_code_length, sitem->code.c_str());

        int ret = ut_subscribe(citem);
        free(citem);
        return ret;
    }

    // 多品种相同字段订阅
    int subscribe(int code_count, ut_code_string* codes, sub_fields_c* fields)
    {
        return ut_subscribe_multi(code_count, codes, fields);
    }

    // 多品种相同字段订阅
    int subscribe(code_list* codes, sub_fields* fields)
    {
        int code_count = codes->size();
        int fn = fields->size();
        if (code_count == 0 || fn == 0)
            return 0;

        ut_code_string* sub_codes = new ut_code_string[code_count];//(ut_code_string*) malloc(sizeof(ut_code_string) * code_count);
        for (int i = 0; i < code_count; i++)
        {
            strcpy_s(sub_codes[i], max_code_length, codes->at(i).c_str());
        }

        sub_fields_c* sub_fields = (sub_fields_c*) malloc(sizeof(sub_fields_c) + (fn-1) * sizeof(int));
        sub_fields->count = fn;
        memcpy(sub_fields->fields, &fields->at(0), sizeof(int) * fn);
        
        int ret = ut_subscribe_multi(code_count, sub_codes, sub_fields);
        free(sub_fields);
        delete [] sub_codes;
        return ret;
    }

    // 多品种不同字段订阅
    int subscribe(sub_list* slist)  
    {
        int code_count = slist->size();
        if (code_count == 0)
            return XYUT_OK;

        sub_item_c** items = new sub_item_c*[code_count];

        for (int i = 0; i < code_count; i++)
        {
            int fn = slist->at(i).fields.size();
            items[i] = (sub_item_c*)malloc(sizeof(sub_item_c) + (fn-1) * sizeof(sub_fields_c));
            strcpy_s(items[i]->code, max_code_length, slist->at(i).code.c_str());
            items[i]->fields.count = fn;
            memcpy(items[i]->fields.fields, &(slist->at(i).fields[0]), fn * sizeof(int));
        }

        int ret = ut_subscribe_multi_ex(code_count, items);
        
        for(int i = 0; i < code_count; i++)
        {
            free(items[i]);
        }
        delete []items;

        return ret;
    }
    
    //订阅逐笔成交数据
    int subscribe_transactions(code_list* codes)
    {
        int code_count = codes->size();
        if (code_count == 0)
            return XYUT_OK;

        ut_code_string* sub_codes = new ut_code_string[code_count];//(ut_code_string*) malloc(sizeof(ut_code_string) * code_count);
        for (int i = 0; i < code_count; i++)
        {
            strcpy_s(sub_codes[i], max_code_length, codes->at(i).c_str());
        }

        int ret = ut_subscribe_transactions(code_count, sub_codes);
        delete [] sub_codes;
        return ret;

    }

    //订阅逐笔数据，暂未开放
    int subscribe_orders(code_list* codes);
    int subscribe_order_queues(code_list* codes);
	
    //获得快照
	int get_snapshot(sub_list* slist)
    {
        int code_count = slist->size();
        if (code_count == 0)
            return XYUT_OK;

        sub_item_c** items = new sub_item_c*[code_count];

        for (int i = 0; i < code_count; i++)
        {
            int fn = slist->at(i).fields.size();
            items[i] = (sub_item_c*)malloc(sizeof(sub_item_c) + (fn-1) * sizeof(sub_fields_c));
            strcpy_s(items[i]->code, max_code_length, slist->at(i).code.c_str());
            items[i]->fields.count = fn;
            memcpy(items[i]->fields.fields, &(slist->at(i).fields[0]), fn * sizeof(int));
        }

        int ret = ut_get_snapshot(code_count, items);
        
        for(int i = 0; i < code_count; i++)
        {
            free(items[i]);
        }
        delete []items;

        return ret;
    }
	
    //获取基础信息，暂未开放
	int get_baseinfo(base_info_req *bir);
	
    //退订
	int unsubscribe(unsub_struct *unsubscribe)
    {
        unsigned n = unsubscribe->codes.size();
        if (n == 0)
            return XYUT_OK;
        
        ut_code_string* p = new ut_code_string[n];
        for (unsigned i = 0; i < n; i++)
        {
            strcpy(p[i], unsubscribe->codes[i].c_str());
        }
        int res = ut_unsubscribe(unsubscribe->sub_type, n, p);
        delete []p;
        return res;
    }

    //全体退订
    int unsubscribe_all(int sub_type)
    {
        return ut_unsubscribe_all(sub_type);
    }

    //设置用户参数
    int set_config(int config_item, int value)
    {
        return ut_set_config(config_item, value);
    }

    //获取用户参数
    int get_config(int config_item, int& value)
    {
        return ut_get_config(config_item, &value);
    }
    
	//释放api
	int release() 
    {
        return ut_release();
    }
    ~xyzq_ut_api() {};

private:
    xyzq_ut_api() {};
    static xyzq_ut_spi* custom_spi(xyzq_ut_spi* new_spi = NULL) // NULL: get; non_NULL: set
    {
        static xyzq_ut_spi* m_spi = NULL;
        if (new_spi)
            m_spi = new_spi;
        return m_spi;
    }

    // 内部使用，请勿更改
    void static __stdcall virtual_callback (int msgtype, void* msg_body)
    {
        xyzq_ut_spi* spi = custom_spi();
        if (!spi)
            return;

        switch(msgtype)
        {
        case ut_error_msg:
            {
            error_msg msg;
            error_msg_c* p = (error_msg_c*)msg_body;
            msg.err_code = p->err_code;
            msg.related_packet_id = p->related_packet_id;
            msg.msg = p->msg;
            spi->rsp_error(&msg);
            }
            break;
        case ut_status_changed_msg:
            spi->rsp_status_changed((int)msg_body);
            break;
        case ut_market_data_msg:
            {
                ut_data_c* p = (ut_data_c *)msg_body;
                ut_data data;
                data.object_type = p->object_type;
                data.xyzq_code = p->xyzq_code;
                data.quotations.insert(data.quotations.end(), &p->quotations[0], &p->quotations[p->data_length]);
                spi->rsp_market_data(&data);    
            }
            
            break;
        case ut_transactions_msg:
            {
                ut_data_c* p = (ut_data_c *)msg_body;
                ut_data data;
                data.object_type = p->object_type;
                data.xyzq_code = p->xyzq_code;
                data.quotations.insert(data.quotations.end(), &p->quotations[0], &p->quotations[p->data_length]);
                spi->rsp_transactions(&data);    
            }
            break;
        case ut_orders_msg:
            {
                ut_data_c* p = (ut_data_c *)msg_body;
                ut_data data;
                data.object_type = p->object_type;
                data.xyzq_code = p->xyzq_code;
                data.quotations.insert(data.quotations.end(), &p->quotations[0], &p->quotations[p->data_length]);
                spi->rsp_orders(&data);    
            }
            break;
        case ut_order_list_msg:
            {
                ut_data_c* p = (ut_data_c *)msg_body;
                ut_data data;
                data.object_type = p->object_type;
                data.xyzq_code = p->xyzq_code;
                //data.quotations.reserve(p->data_length);
                data.quotations.insert(data.quotations.end(), &p->quotations[0], &p->quotations[p->data_length]);
                spi->rsp_order_list(&data);    
            }
            break;
        case ut_base_info_msg:
            break;
        case ut_null_msg:
        default:
            break;
        }
    }

};

#endif

