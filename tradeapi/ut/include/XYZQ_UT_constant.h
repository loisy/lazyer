#pragma once

//////////////////////////////////////////////////////////
// Error Codes
//////////////////////////////////////////////////////////
const int XYUT_OK                               = 0;

const int XYUT_ERR_GENERAL                      = -1000;

const int XYUT_ERR_UNKNOWN                      = -1001;
const int XYUT_ERR_INTERNAL                     = -1002;
const int XYUT_ERR_UNAUTHORIZED                 = -1003;
const int XYUT_ERR_WRONG_PASSWORD               = -1004;
const int XYUT_ERR_LOGIN_LIMIT_EXCEEDED         = -1005;
const int XYUT_ERR_NOT_INITIALIZED              = -1006;
const int XYUT_ERR_INVALID_SPI                  = -1007;
const int XYUT_ERR_KICKOFF_BY_ANOTHER           = -1008;
const int XYUT_ERR_NOT_IMPLEMENTED              = -1009;
const int XYUT_ERR_INVALID_IP                   = -1010;
const int XYUT_ERR_INVALID_NEW_PASSWORD         = -1011;
const int XYUT_ERR_INVALID_PARAMETER            = -1012;

const int XYUT_ERR_REQUEST                      = -2000;

const int XYUT_ERR_UNSUPPORTED_CODE             = -2001;
const int XYUT_ERR_UNSUPPORTED_INDICATOR        = -2002;
const int XYUT_ERR_UNAUTHORIZED_CODE            = -2003;
const int XYUT_ERR_UNAUTHORIZED_INDICATOR       = -2004;
const int XYUT_ERR_SUBSCRIBE_LIMIT_EXCEEDED     = -2005;
const int XYUT_ERR_BAD_REQUEST_PACKET           = -2006;
const int XYUT_ERR_UNSUPPORTED_CONFIG_SETTING   = -2007;
const int XYUT_ERR_BAD_API_PARAMETERS           = -2008;
const int XYUT_ERR_TRANS_SUB_LIMIT_EXCEEDED     = -2009;
const int XYUT_ERR_ORDERS_SUB_LIMIT_EXCEEDED    = -2010;

const int XYUT_ERR_NETWORK                      = -3000;

const int XYUT_ERR_SERVER_NOT_ACCESSABLE        = -3001;
const int XYUT_ERR_CONNECTION_LOST              = -3002;
const int XYUT_ERR_SENDING_FAILED               = -3003;
const int XYUT_ERR_RECEIVING_FAILED             = -3004;
const int XYUT_ERR_NETWORK_TIMEOUT              = -3005;


const int XYUT_ERR_DATA                         = -4000;
const int XYUT_ERR_NO_DATA_AVAILABLE            = -4001;

//////////////////////////////////////////////////////////
// Info/Notice Codes
//////////////////////////////////////////////////////////
const int XYUT_INFO_LOGIN_SUCCESS               = 1;

const int XYUT_INFO_CONNECTION_UNESTABLISHD     = 0;
const int XYUT_INFO_CONNECTION_OK               = 1;
const int XYUT_INFO_CONNECTION_LOST             = 2;
const int XYUT_INFO_CONNECTION_CLOSED           = 3;
const int XYUT_INFO_CONNECTION_KICKED_OFF       = 4;


//////////////////////////////////////////////////////////
// Config Codes
//////////////////////////////////////////////////////////
const int XYUT_CONFIG_AUTO_RELOGIN                      = 0x01;
const int   XYUT_CONFIG_VALUE_NOT_RELOGIN   = 0;
const int   XYUT_CONFIG_VALUE_AUTO_RELOGIN  = 1;

const int XYUT_CONFIG_RETRIEVE_FLOAT_AS_INT             = 0x02;
const int   XYUT_CONFIG_VALUE_RETRIEVE_FLOAT_AS_DOUBLE  = 0;
const int   XYUT_CONFIG_VALUE_RETRIEVE_FLOAT_AS_INT     = 1;

//////////////////////////////////////////////////////////
// Order Types
//////////////////////////////////////////////////////////
const int XYUT_ORDER_TYPE_UNKNOWN           = 0;  // δ֪ί������
const int XYUT_ORDER_TYPE_BID               = 1;  // ��ͨ��
const int XYUT_ORDER_TYPE_ASK               = 2;  // ��ͨ��
const int XYUT_ORDER_TYPE_WITHDRAW          = 3;  // ��ͨ����
const int XYUT_ORDER_TYPE_FAK_BID           = 4;  //����ʱ�ɽ�ʣ�೷������
const int XYUT_ORDER_TYPE_FAK_ASK           = 5;  //����ʱ�ɽ�ʣ�೷������
const int XYUT_ORDER_TYPE_ETF_PURCHASE      = 6;  // ETF�����깺
const int XYUT_ORDER_TYPE_ETF_REDEMPTION    = 7;  // ETF�������
const int XYUT_ORDER_TYPE_FIVE_FAK_BID      = 8;  //�������嵵��ʱ�ɽ�ʣ�೷������
const int XYUT_ORDER_TYPE_FIVE_FAK_ASK      = 9;  //�������嵵��ʱ�ɽ�ʣ�೷������
const int XYUT_ORDER_TYPE_FOK_BID           = 10;  //��ȫ��ɽ���������
const int XYUT_ORDER_TYPE_FOK_ASK           = 11;  //��ȫ��ɽ���������
const int XYUT_ORDER_TYPE_SELF_OPT_BID      = 12;  //���������ż۸���
const int XYUT_ORDER_TYPE_SELF_OPT_ASK      = 13;  //���������ż۸���
const int XYUT_ORDER_TYPE_SELF_OPT_WITHDRAW = 14;  //���������ż۸񡱳���
const int XYUT_ORDER_TYPE_OPP_OPT_BID       = 15;  //�����ַ����ż۸���
const int XYUT_ORDER_TYPE_OPP_OPT_ASK       = 16;  //�����ַ����ż۸���
const int XYUT_ORDER_TYPE_OPP_OPT_WITHDRAW  = 17;  //�����ַ����ż۸񡱳���


//////////////////////////////////////////////////////////
// Transaction Types
//////////////////////////////////////////////////////////
const int XYUT_TRANS_TYPE_UNKNOWN           = 0;  // δ֪�ɽ�����
const int XYUT_TRANS_TYPE_DONE              = 1;  // ��ͨ�ɽ�
const int XYUT_TRANS_TYPE_WITHDRAW          = 2;  // ��ͨ����
const int XYUT_TRANS_TYPE_FAK_WITHDRAW      = 3;  //����ʱ�ɽ�ʣ�೷�����Զ������ر�
const int XYUT_TRANS_TYPE_ETF               = 4;  // ETF��������ɹ��ر�
const int XYUT_TRANS_TYPE_ETF_WITHDRAW      = 5;  // ETF�������곷���ر�
const int XYUT_TRANS_TYPE_FIVE_FAK_WITHDRAW = 6;  //�������嵵��ʱ�ɽ�ʣ�೷�����Զ������ر�
const int XYUT_TRANS_TYPE_FOK_WITHDRAW      = 7;  //��ȫ��ɽ��������Զ������ر�
const int XYUT_TRANS_TYPE_SELF_OPT_WITHDRAW = 8;  //���������ż۸񡱵ĳ����ر�
const int XYUT_TRANS_TYPE_OPP_OPT_WITHDRAW  = 9;  //�����ַ����ż۸񡱵ĳ����ر�
const int XYUT_TRANS_TYPE_CASH_SUBST_LIST   = 10;  // ETF���������ֽ������ϸ�ر�
