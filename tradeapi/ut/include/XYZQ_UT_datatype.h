#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define max_code_length         32
#define short_string_length     64
#define long_string_length      512
typedef char ut_code_string[32];
typedef char ut_short_string[64];
typedef char ut_long_string[512];

#ifdef __cplusplus
// ��������
const unsigned short ut_null_type       = 0;
const unsigned short ut_int_type        = 1;
const unsigned short ut_uint_type       = 2;
const unsigned short ut_int64_type      = 3;
const unsigned short ut_uint64_type     = 4;
const unsigned short ut_double_type     = 5;
const unsigned short ut_string_type     = 6;

// ��������
const int ut_all_sub            = 0;
const int ut_snapshot_sub       = 1;
const int ut_transaction_sub    = 2;
const int ut_order_sub          = 3;
const int ut_order_queue_sub    = 4;

#else
// ��������
#define ut_null_type       0
#define ut_int_type        1
#define ut_uint_type       2
#define ut_int64_type      3
#define ut_uint64_type     4
#define ut_double_type     5
#define ut_string_type     6

// ��������
#define ut_all_sub            0
#define ut_snapshot_sub       1
#define ut_transaction_sub    2
#define ut_order_sub          3
#define ut_order_queue_sub    4

#endif

// Ʒ������
#define ut_stocktype_unknown        0
#define ut_stocktype_index          1
#define ut_stocktype_stock          2
#define ut_stocktype_fund           3
#define ut_stocktype_bond           4
#define ut_stocktype_option         5
#define ut_stocktype_future         6
#define ut_stocktype_others         100

// �������ݽṹ
typedef struct _ut_data_item
{
    unsigned short tag;
    unsigned short dtype;
    union 
    {
        int             int_value;
        unsigned int    uint_value;
        __int64         int64_value;
        double          double_value;
        char*           string_value;
    };
} ut_data_item;

#ifdef __cplusplus
#include <string>
#include <map>
#include <vector>

using namespace std;

//�޸�����
typedef struct change_pwd
{
	string account_no;
	string username;
	string oldpassword;
	string newpassword;
} change_pwd;

//������Ϣ��
typedef struct error_msg_struct
{
	int err_code;
	int related_packet_id;
	string msg;
} error_msg;

//��¼��
typedef struct authorize_struct
{
	string account_no;
	string username;
	string password;
} authorize_struct;

//���ġ�ȡ���հ�
// �ֶα�
typedef vector<int> sub_fields;

// ����code���ı�
typedef struct sub_item
{
    string code;
    sub_fields fields;
} sub_item;

// ���code���ı�
typedef vector<sub_item> sub_list;
typedef vector<string> code_list;

//�˶���
typedef struct unsub
{
	int sub_type;
	code_list codes;
} unsub_struct;

//�������Ͱ�
typedef struct _ut_data
{
    int object_type;
    string xyzq_code;
    vector<ut_data_item> quotations;
}  ut_data;


//������Ϣ�����
typedef struct base_info_req
{
	string xyzq_code;
	vector<int> tags;
} base_info_req;

typedef struct ttv
{
	int tag;
	int tagtype;
	int tagvalue;
} ttv;

//������Ϣ���ذ�
typedef struct rsp_base_info_s
{
	char code_type;
	string xyzq_code;
	vector<ttv> ttvs;
} rsp_base_info_s;

#endif

// C style difinitions
typedef void (WINAPI *xyzq_ut_c_spi) (int msgtype, void* msg_body);
///////////////////////////
// c style callback msgtype
///////////////////////////
#define ut_null_msg               0     //δ֪��Ϣ
#define ut_error_msg              1 	//������Ϣ��Ӧ
#define ut_status_changed_msg     2	    //״̬��Ӧ
#define ut_market_data_msg        3	    //����Ʒ����������
#define ut_transactions_msg       4	    //����Ʒ����ʳɽ�����
#define ut_orders_msg             5     //����Ʒ�����ί������
#define ut_order_list_msg         6	    //����Ʒ��ί�ж�������
#define ut_base_info_msg          7	    //��ѯ������Ϣ��Ӧ

typedef struct _ut_his_data_c
{
    ut_code_string xyzq_code;
    int const_data_count;
    ut_data_item const_data[8];
    ut_short_string const_data_brief[8];
    int data_length;
    ut_data_item quotations[1];
}  ut_his_data_c;

typedef struct _ut_data_c
{
    int object_type;
    ut_code_string xyzq_code;
    int data_length;
    ut_data_item quotations[1];
}  ut_data_c;

typedef struct error_msg_struct_c
{
	int err_code;
	int related_packet_id;
	ut_long_string msg;
} error_msg_c;

//���ġ�ȡ���հ�
// �ֶα�
typedef struct sub_fields_c
{
    int count;
    int fields[1];
} sub_fields_c;

// ����code���ı�
typedef struct sub_item_c
{
    ut_code_string code;
    sub_fields_c fields;
} sub_item_c;
