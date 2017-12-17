/////////////////////////////////////////////////////////////////////////
///@system ��һ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file ZQThostFtdcTraderApi.h
///@brief �����˿ͻ��˽ӿ�
///@history 
///20060106	�Ժ��		�������ļ�
/////////////////////////////////////////////////////////////////////////

#if !defined(ZQTHOST_FTDCTRADERAPI_H)
#define ZQTHOST_FTDCTRADERAPI_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ZQThostFtdcUserApiStruct.h"

#if defined(ISLIB) && defined(WIN32)
#ifdef LIB_TRADER_API_EXPORT
#define TRADER_API_EXPORT __declspec(dllexport)
#else
#define TRADER_API_EXPORT __declspec(dllimport)
#endif
#else
#define TRADER_API_EXPORT 
#endif

class CZQThostFtdcTraderSpi
{
public:
	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
	virtual void OnFrontConnected(){};
	
	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
	///@param nReason ����ԭ��
	///        0x1001 �����ʧ��
	///        0x1002 ����дʧ��
	///        0x2001 ����������ʱ
	///        0x2002 ��������ʧ��
	///        0x2003 �յ�������
	virtual void OnFrontDisconnected(int nReason){};
		
	///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
	///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
	virtual void OnHeartBeatWarning(int nTimeLapse){};
	
	///�ͻ�����֤��Ӧ
	virtual void OnRspAuthenticate(CZQThostFtdcRspAuthenticateField *pRspAuthenticateField, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};


	///����Ӧ��
	virtual void OnRspError(CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��¼������Ӧ
	virtual void OnRspUserLogin(CZQThostFtdcRspUserLoginField *pRspUserLogin, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ǳ�������Ӧ
	virtual void OnRspUserLogout(CZQThostFtdcUserLogoutField *pUserLogout, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û����������Ӧ
	virtual void OnRspUserPasswordUpdate(CZQThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����¼��������Ӧ
	virtual void OnRspOrderInsert(CZQThostFtdcInputOrderField *pInputOrder, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��������¼��������Ӧ
	virtual void OnRspOrderAction(CZQThostFtdcInputOrderActionField *pInputOrderAction, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����֪ͨ
	virtual void OnRtnOrder(CZQThostFtdcOrderField *pOrder) {};

	///�ɽ�֪ͨ
	virtual void OnRtnTrade(CZQThostFtdcTradeField *pTrade) {};

	///����¼�����ر�
	virtual void OnErrRtnOrderInsert(CZQThostFtdcInputOrderField *pInputOrder, CZQThostFtdcRspInfoField *pRspInfo) {};

	///������������ر�
	virtual void OnErrRtnOrderAction(CZQThostFtdcOrderActionField *pOrderAction, CZQThostFtdcRspInfoField *pRspInfo) {};

	///����֪ͨ
	virtual void OnRtnTradingNotice(CZQThostFtdcTradingNoticeInfoField *pTradingNoticeInfo) {};

	///�ʽ�ת�ƻر�
	virtual void OnRtnTransferFund(CZQThostFtdcTransferFundField *pTransferFund) {};

	///��λת�ƻر�
	virtual void OnRtnTransferPosition(CZQThostFtdcTransferPositionField *pTransferPosition) {};

	///�����ѯ��������Ӧ
	virtual void OnRspQryExchange(CZQThostFtdcExchangeField *pExchange, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ������Ӧ
	virtual void OnRspQryDepthMarketData(CZQThostFtdcDepthMarketDataField *pDepthMarketData, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ֤ȯ��Ӧ
	virtual void OnRspQrySecurity(CZQThostFtdcSecurityField *pSecurity, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯETF�嵥��Ӧ
	virtual void OnRspQryETFFile(CZQThostFtdcETFFileField *pETFFile, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯETF�ɷ�֤ȯ��Ӧ
	virtual void OnRspQryETFBasket(CZQThostFtdcETFBasketField *pETFBasket, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ�¹���Ϣ��Ӧ
	virtual void OnRspQrySubscribingShares(CZQThostFtdcSubscribingSharesField *pSubscribingShares, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ��Ѻ�걨����
	virtual void OnRspQryPledgeOrderInfo(CZQThostFtdcPledgeOrderInfoField *pPledgeOrderInfo, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ�г���Ӧ
	virtual void OnRspQryMarket(CZQThostFtdcMarketField *pMarket, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ֤ȯƷ����Ӧ
	virtual void OnRspQrySecurityProduct(CZQThostFtdcSecurityProductField *pSecurityProduct, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ֤ȯ�����Ӧ
	virtual void OnRspQrySecurityClass(CZQThostFtdcSecurityClassField *pSecurityClass, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ������Ӧ
	virtual void OnRspQryOrder(CZQThostFtdcOrderField *pOrder, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ�ɽ���Ӧ
	virtual void OnRspQryTrade(CZQThostFtdcTradeField *pTrade, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ�ʽ��˻���Ӧ
	virtual void OnRspQryTradingAccount(CZQThostFtdcTradingAccountField *pTradingAccount, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯͶ����֤ȯ�ֲ���Ӧ
	virtual void OnRspQryInvestorSecurityPosition(CZQThostFtdcInvestorSecurityPositionField *pInvestorSecurityPosition, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯͶ������Ѻ�ֲ���Ӧ
	virtual void OnRspQryInvestorPledgePosition(CZQThostFtdcInvestorPledgePositionField *pInvestorPledgePosition, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯͶ������Ѻ�ع���Ӧ
	virtual void OnRspQryInvestorPledgeInfo(CZQThostFtdcInvestorPledgeInfoField *pInvestorPledgeInfo, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ�����ʽ���ϸ��Ӧ
	virtual void OnRspQryOrderFundDetail(CZQThostFtdcOrderFundDetailField *pOrderFundDetail, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯͶ������Ӧ
	virtual void OnRspQryInvestor(CZQThostFtdcInvestorField *pInvestor, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ�����˻���Ӧ
	virtual void OnRspQryTradingCode(CZQThostFtdcTradingCodeField *pTradingCode, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯͶ�ʵ�Ԫ��Ӧ
	virtual void OnRspQryInvestUnit(CZQThostFtdcInvestUnitField *pInvestUnit, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯͶ�ʵ�Ԫ�뽻���ʽ��˻���ϵ��Ӧ
	virtual void OnRspQryInvestUnitAndTradingAcct(CZQThostFtdcInvestUnitAndTradingAcctField *pInvestUnitAndTradingAcct, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯͶ�ʵ�Ԫ�뽻���û���Ӧ
	virtual void OnRspQryInvestUnitAndUser(CZQThostFtdcInvestUnitAndUserField *pInvestUnitAndUser, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯͶ����Ӷ����Ӧ
	virtual void OnRspQryBrokerage(CZQThostFtdcBrokerageField *pBrokerage, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ�¹��깺�����Ӧ
	virtual void OnRspQrySubscribingSharesQuota(CZQThostFtdcSubscribingSharesQuotaField *pSubscribingSharesQuota, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ��׼ȯʹ������Ӧ
	virtual void OnRspQryRepoRatio(CZQThostFtdcRepoRatioField *pRepoRatio, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ�ع��Ŵ�����Ӧ
	virtual void OnRspQryRepurchaseMaxTimes(CZQThostFtdcRepurchaseMaxTimesField *pRepurchaseMaxTimes, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ�ʽ�ת����Ӧ
	virtual void OnRspQryTransferFund(CZQThostFtdcTransferFundField *pTransferFund, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ��λת����Ӧ
	virtual void OnRspQryTransferPosition(CZQThostFtdcTransferPositionField *pTransferPosition, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Ȩ¼����Ӧ
	virtual void OnRspExecOrderInsert(CZQThostFtdcInputExecOrderField *pInputExecOrder, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Ȩ֪ͨ
	virtual void OnRtnExecOrder(CZQThostFtdcExecOrderField *pExecOrder) {};

	///��Ȩ¼�����֪ͨ
	virtual void OnErrRtnExecOrderInsert(CZQThostFtdcInputExecOrderField *pInputExecOrder, CZQThostFtdcRspInfoField *pRspInfo) {};

	///��Ȩ����¼����Ӧ
	virtual void OnRspExecOrderAction(CZQThostFtdcInputExecOrderActionField *pInputExecOrderAction, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Ȩ����¼�����֪ͨ
	virtual void OnErrRtnExecOrderAction(CZQThostFtdcExecOrderActionField *pExecOrderAction, CZQThostFtdcRspInfoField *pRspInfo) {};

	///����¼����Ӧ
	virtual void OnRspLockInsert(CZQThostFtdcInputLockField *pInputLock, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����֪ͨ
	virtual void OnRtnLock(CZQThostFtdcLockField *pLock) {};

	///����¼�����֪ͨ
	virtual void OnErrRtnLockInsert(CZQThostFtdcInputLockField *pInputLock, CZQThostFtdcRspInfoField *pRspInfo) {};

	///��ȯת����Ӧ
	virtual void OnRspSecurityTransfer(CZQThostFtdcInputSecurityTransferField *pInputSecurityTransfer, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ȯת��֪ͨ
	virtual void OnRtnSecurityTransfer(CZQThostFtdcSecurityTransferField *pSecurityTransfer) {};

	///��ȯת�ƴ���֪ͨ
	virtual void OnErrRtnSecurityTransfer(CZQThostFtdcInputSecurityTransferField *pInputSecurityTransfer, CZQThostFtdcRspInfoField *pRspInfo) {};

	///������Ȩ��Լ��ѯ��Ӧ
	virtual void OnRspQryInstrument(CZQThostFtdcInstrumentField *pInstrument, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///������ѯ��Ӧ
	virtual void OnRspQryLock(CZQThostFtdcLockField *pLock, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ִ�������ѯ��Ӧ
	virtual void OnRspQryExecOrder(CZQThostFtdcExecOrderField *pExecOrder, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ֲֲ�ѯ��Ӧ
	virtual void OnRspQryLockPosition(CZQThostFtdcLockPositionField *pLockPosition, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ͷ���߱�֤���ʲ�ѯ��Ӧ
	virtual void OnRspQryMarginRate(CZQThostFtdcMarginRateField *pMarginRate, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ͷ���������Ȳ�ѯ��Ӧ
	virtual void OnRspQryLimitAmount(CZQThostFtdcLimitAmountField *pLimitAmount, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ͷ���ֲ߳����Ʋ�ѯ��Ӧ
	virtual void OnRspQryLimitPosition(CZQThostFtdcLimitPositionField *pLimitPosition, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Ȩָ�ɲ�ѯ��Ӧ
	virtual void OnRspQryExerciseAssignment(CZQThostFtdcExerciseAssignmentField *pExerciseAssignment, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ͷ���ߺ�Լ�ֲֲ�ѯ��Ӧ
	virtual void OnRspQryInvestorPosition(CZQThostFtdcInvestorPositionField *pInvestorPosition, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ȯת�Ʋ�ѯ��Ӧ
	virtual void OnRspQrySecurityTransfer(CZQThostFtdcSecurityTransferField *pSecurityTransfer, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���п���ʽ������Ϣ��ѯ��Ӧ
	virtual void OnRspQryLOFInfo(CZQThostFtdcLOFInfoField *pLOFInfo, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���п���ʽ�����ӻ�����Ϣ��ѯ��Ӧ
	virtual void OnRspQryLOFSubInfo(CZQThostFtdcLOFSubInfoField *pLOFSubInfo, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ֱ�ӻ���¼����Ӧ
	virtual void OnRspCashRepayInsert(CZQThostFtdcInputCashRepayField *pInputCashRepay, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ֱ�ӻ���ر�
	virtual void OnRtnCashRepay(CZQThostFtdcCashRepayField *pCashRepay) {};

	///ֱ�ӻ���¼�����֪ͨ
	virtual void OnErrRtnCashRepayInsert(CZQThostFtdcInputCashRepayField *pInputCashRepay, CZQThostFtdcRspInfoField *pRspInfo) {};

	///��ѯ������ȯֱ�ӻ�����Ϣ��Ӧ
	virtual void OnRspQryCashRepay(CZQThostFtdcCashRepayField *pCashRepay, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ѯͶ����������ȯ��Ϣ��Ӧ
	virtual void OnRspQryCreditInfo(CZQThostFtdcCreditInfoField *pCreditInfo, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ѯͶ����������ȯ����֤ȯͷ����Ӧ
	virtual void OnRspQryCreditSecurityPosition(CZQThostFtdcCreditSecurityPositionField *pCreditSecurityPosition, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯͶ�������ú�Լ��Ӧ
	virtual void OnRspQryCreditContract(CZQThostFtdcCreditContractField *pCreditContract, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯͶ����������ȯ������ϸ��Ӧ
	virtual void OnRspQryCreditRepayment(CZQThostFtdcCreditRepaymentField *pCreditRepayment, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯͶ����������ȯ���֤ȯ��Ϣ��Ӧ
	virtual void OnRspQryCreditUnderlying(CZQThostFtdcCreditUnderlyingField *pCreditUnderlying, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯͶ����������ȯ����֤ȯ��Ϣ��Ӧ
	virtual void OnRspQryCreditCollateral(CZQThostFtdcCreditCollateralField *pCreditCollateral, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯͶ����������ȯ�����ʽ�ͷ����Ӧ
	virtual void OnRspQryCreditFundPosition(CZQThostFtdcCreditFundPositionField *pCreditFundPosition, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
};

class TRADER_API_EXPORT CZQThostFtdcTraderApi
{
public:
	///����TraderApi
	///@param pszFlowPath ����������Ϣ�ļ���Ŀ¼��Ĭ��Ϊ��ǰĿ¼
	///@return ��������UserApi
	//modify for udp marketdata
	static CZQThostFtdcTraderApi *CreateFtdcTraderApi(const char *pszFlowPath = "", const bool bIsUsingUdp=false);
	
	///��ȡAPI�汾��
	///@return �汾��
	static const char* GetApiVersion();
	
	///ɾ���ӿڶ�����
	///@remark ����ʹ�ñ��ӿڶ���ʱ,���øú���ɾ���ӿڶ���
	virtual void Release() = 0;
	
	///��ʼ��
	///@remark ��ʼ�����л���,ֻ�е��ú�,�ӿڲſ�ʼ����
	virtual void Init() = 0;
	
	///�ȴ��ӿ��߳̽�������
	///@return �߳��˳�����
	virtual int Join() = 0;
	
	///ע��ǰ�û������ַ
	///@param pszFrontAddress��ǰ�û������ַ��
	///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:17001���� 
	///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����17001������������˿ںš�
	virtual void RegisterFront(char *pszFrontAddress) = 0;
	
	///ע��ص��ӿ�
	///@param pSpi �����Իص��ӿ����ʵ��
	virtual void RegisterSpi(CZQThostFtdcTraderSpi *pSpi) = 0;
	
	///����˽������
	///@param nResumeType ˽�����ش���ʽ  
	///        THOST_TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        THOST_TERT_RESUME:���ϴ��յ�������
	///        THOST_TERT_QUICK:ֻ���͵�¼��˽����������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ�˽���������ݡ�
	virtual void SubscribePrivateTopic(ZQTHOST_TE_RESUME_TYPE nResumeType) = 0;
	
	///���Ĺ�������
	///@param nResumeType �������ش���ʽ  
	///        THOST_TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        THOST_TERT_RESUME:���ϴ��յ�������
	///        THOST_TERT_QUICK:ֻ���͵�¼�󹫹���������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ������������ݡ�
	virtual void SubscribePublicTopic(ZQTHOST_TE_RESUME_TYPE nResumeType) = 0;

	///�ͻ�����֤����
	virtual int ReqAuthenticate(CZQThostFtdcReqAuthenticateField *pReqAuthenticateField, int nRequestID) = 0;

	///�û���¼����
	virtual int ReqUserLogin(CZQThostFtdcReqUserLoginField *pReqUserLoginField, int nRequestID) = 0;
	

	///�ǳ�����
	virtual int ReqUserLogout(CZQThostFtdcUserLogoutField *pUserLogout, int nRequestID) = 0;

	///�û������������
	virtual int ReqUserPasswordUpdate(CZQThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID) = 0;

	///����¼������
	virtual int ReqOrderInsert(CZQThostFtdcInputOrderField *pInputOrder, int nRequestID) = 0;

	///��������¼������
	virtual int ReqOrderAction(CZQThostFtdcInputOrderActionField *pInputOrderAction, int nRequestID) = 0;

	///�����ѯ������
	virtual int ReqQryExchange(CZQThostFtdcQryExchangeField *pQryExchange, int nRequestID) = 0;

	///�����ѯ����
	virtual int ReqQryDepthMarketData(CZQThostFtdcQryDepthMarketDataField *pQryDepthMarketData, int nRequestID) = 0;

	///�����ѯ֤ȯ
	virtual int ReqQrySecurity(CZQThostFtdcQrySecurityField *pQrySecurity, int nRequestID) = 0;

	///�����ѯETF�嵥
	virtual int ReqQryETFFile(CZQThostFtdcQryETFFileField *pQryETFFile, int nRequestID) = 0;

	///�����ѯETF�ɷ�֤ȯ
	virtual int ReqQryETFBasket(CZQThostFtdcQryETFBasketField *pQryETFBasket, int nRequestID) = 0;

	///�����ѯ�¹���Ϣ
	virtual int ReqQrySubscribingShares(CZQThostFtdcQrySubscribingSharesField *pQrySubscribingShares, int nRequestID) = 0;

	///�����ѯ��Ѻ�걨����
	virtual int ReqQryPledgeOrderInfo(CZQThostFtdcQryPledgeOrderInfoField *pQryPledgeOrderInfo, int nRequestID) = 0;

	///�����г�
	virtual int ReqQryMarket(CZQThostFtdcQryMarketField *pQryMarket, int nRequestID) = 0;

	///�����ѯ֤ȯƷ��
	virtual int ReqQrySecurityProduct(CZQThostFtdcQrySecurityProductField *pQrySecurityProduct, int nRequestID) = 0;

	///�����ѯ֤ȯ���
	virtual int ReqQrySecurityClass(CZQThostFtdcQrySecurityClassField *pQrySecurityClass, int nRequestID) = 0;

	///�����ѯ����
	virtual int ReqQryOrder(CZQThostFtdcQryOrderField *pQryOrder, int nRequestID) = 0;

	///�����ѯ�ɽ�
	virtual int ReqQryTrade(CZQThostFtdcQryTradeField *pQryTrade, int nRequestID) = 0;

	///�����ѯ�ʽ��˻�
	virtual int ReqQryTradingAccount(CZQThostFtdcQryTradingAccountField *pQryTradingAccount, int nRequestID) = 0;

	///�����ѯͶ����֤ȯ�ֲ�
	virtual int ReqQryInvestorSecurityPosition(CZQThostFtdcQryInvestorSecurityPositionField *pQryInvestorSecurityPosition, int nRequestID) = 0;

	///�����ѯͶ������Ѻ�ֲ�
	virtual int ReqQryInvestorPledgePosition(CZQThostFtdcQryInvestorPledgePositionField *pQryInvestorPledgePosition, int nRequestID) = 0;

	///�����ѯͶ������Ѻ�ع�
	virtual int ReqQryInvestorPledgeInfo(CZQThostFtdcQryInvestorPledgeInfoField *pQryInvestorPledgeInfo, int nRequestID) = 0;

	///�����ѯ�����ʽ���ϸ
	virtual int ReqQryOrderFundDetail(CZQThostFtdcQryOrderFundDetailField *pQryOrderFundDetail, int nRequestID) = 0;

	///�����ѯͶ����
	virtual int ReqQryInvestor(CZQThostFtdcQryInvestorField *pQryInvestor, int nRequestID) = 0;

	///�����ѯ�����˻�
	virtual int ReqQryTradingCode(CZQThostFtdcQryTradingCodeField *pQryTradingCode, int nRequestID) = 0;

	///�����ѯͶ�ʵ�Ԫ
	virtual int ReqQryInvestUnit(CZQThostFtdcQryInvestUnitField *pQryInvestUnit, int nRequestID) = 0;

	///�����ѯͶ�ʵ�Ԫ�뽻���ʽ��˻���ϵ
	virtual int ReqQryInvestUnitAndTradingAcct(CZQThostFtdcQryInvestUnitAndTradingAcctField *pQryInvestUnitAndTradingAcct, int nRequestID) = 0;

	///�����ѯͶ�ʵ�Ԫ�뽻���û���ϵ
	virtual int ReqQryInvestUnitAndUser(CZQThostFtdcQryInvestUnitAndUserField *pQryInvestUnitAndUser, int nRequestID) = 0;

	///�����ѯͶ����Ӷ��
	virtual int ReqQryBrokerage(CZQThostFtdcQryBrokerageField *pQryBrokerage, int nRequestID) = 0;

	///�����ѯ�¹��깺���
	virtual int ReqQrySubscribingSharesQuota(CZQThostFtdcQrySubscribingSharesQuotaField *pQrySubscribingSharesQuota, int nRequestID) = 0;

	///�����ѯ��׼ȯʹ����
	virtual int ReqQryRepoRatio(CZQThostFtdcQryRepoRatioField *pQryRepoRatio, int nRequestID) = 0;

	///�����ѯ�ع��Ŵ���
	virtual int ReqQryRepurchaseMaxTimes(CZQThostFtdcQryRepurchaseMaxTimesField *pQryRepurchaseMaxTimes, int nRequestID) = 0;

	///�����ѯ�ʽ�ת��
	virtual int ReqQryTransferFund(CZQThostFtdcQryTransferFundField *pQryTransferFund, int nRequestID) = 0;

	///�����ѯ��λת��
	virtual int ReqQryTransferPosition(CZQThostFtdcQryTransferPositionField *pQryTransferPosition, int nRequestID) = 0;

	///������Ȩ¼��
	virtual int ReqExecOrderInsert(CZQThostFtdcInputExecOrderField *pInputExecOrder, int nRequestID) = 0;

	///������Ȩ����¼��
	virtual int ReqExecOrderAction(CZQThostFtdcInputExecOrderActionField *pInputExecOrderAction, int nRequestID) = 0;

	///��������¼��
	virtual int ReqLockInsert(CZQThostFtdcInputLockField *pInputLock, int nRequestID) = 0;

	///������ȯת��¼��
	virtual int ReqSecurityTransfer(CZQThostFtdcInputSecurityTransferField *pInputSecurityTransfer, int nRequestID) = 0;

	///������Ȩ��Լ��ѯ
	virtual int ReqQryInstrument(CZQThostFtdcQryInstrumentField *pQryInstrument, int nRequestID) = 0;

	///������ѯ
	virtual int ReqQryLock(CZQThostFtdcQryLockField *pQryLock, int nRequestID) = 0;

	///ִ�������ѯ
	virtual int ReqQryExecOrder(CZQThostFtdcQryExecOrderField *pQryExecOrder, int nRequestID) = 0;

	///�����ֲֲ�ѯ
	virtual int ReqQryLockPosition(CZQThostFtdcQryLockPositionField *pQryLockPosition, int nRequestID) = 0;

	///Ͷ���߱�֤���ʲ�ѯ
	virtual int ReqQryMarginRate(CZQThostFtdcQryMarginRateField *pQryMarginRate, int nRequestID) = 0;

	///Ͷ���������Ȳ�ѯ
	virtual int ReqQryLimitAmount(CZQThostFtdcQryLimitAmountField *pQryLimitAmount, int nRequestID) = 0;

	///Ͷ���ֲ߳����Ʋ�ѯ
	virtual int ReqQryLimitPosition(CZQThostFtdcQryLimitPositionField *pQryLimitPosition, int nRequestID) = 0;

	///��Ȩָ�ɲ�ѯ
	virtual int ReqQryExerciseAssignment(CZQThostFtdcQryExerciseAssignmentField *pQryExerciseAssignment, int nRequestID) = 0;

	///Ͷ���ߺ�Լ�ֲֲ�ѯ
	virtual int ReqQryInvestorPosition(CZQThostFtdcQryInvestorPositionField *pQryInvestorPosition, int nRequestID) = 0;

	///��ȯת�Ʋ�ѯ
	virtual int ReqQrySecurityTransfer(CZQThostFtdcQrySecurityTransferField *pQrySecurityTransfer, int nRequestID) = 0;

	///���п���ʽ������Ϣ��ѯ
	virtual int ReqQryLOFInfo(CZQThostFtdcQryLOFInfoField *pQryLOFInfo, int nRequestID) = 0;

	///���п���ʽ�����ӻ�����Ϣ��ѯ
	virtual int ReqQryLOFSubInfo(CZQThostFtdcQryLOFSubInfoField *pQryLOFSubInfo, int nRequestID) = 0;

	///����ֱ�ӻ���¼��
	virtual int ReqCashRepayInsert(CZQThostFtdcInputCashRepayField *pInputCashRepay, int nRequestID) = 0;

	///��ѯ������ȯֱ�ӻ�����Ϣ
	virtual int ReqQryCashRepay(CZQThostFtdcQryCashRepayField *pQryCashRepay, int nRequestID) = 0;

	///��ѯͶ����������ȯ��Ϣ
	virtual int ReqQryCreditInfo(CZQThostFtdcQryCreditInfoField *pQryCreditInfo, int nRequestID) = 0;

	///��ѯͶ����������ȯ����֤ȯͷ��
	virtual int ReqQryCreditSecurityPosition(CZQThostFtdcQryCreditSecurityPositionField *pQryCreditSecurityPosition, int nRequestID) = 0;

	///�����ѯͶ�������ú�Լ
	virtual int ReqQryCreditContract(CZQThostFtdcQryCreditContractField *pQryCreditContract, int nRequestID) = 0;

	///�����ѯͶ����������ȯ������ϸ
	virtual int ReqQryCreditRepayment(CZQThostFtdcQryCreditRepaymentField *pQryCreditRepayment, int nRequestID) = 0;

	///�����ѯͶ����������ȯ���֤ȯ��Ϣ
	virtual int ReqQryCreditUnderlying(CZQThostFtdcQryCreditUnderlyingField *pQryCreditUnderlying, int nRequestID) = 0;

	///�����ѯͶ����������ȯ����֤ȯ��Ϣ
	virtual int ReqQryCreditCollateral(CZQThostFtdcQryCreditCollateralField *pQryCreditCollateral, int nRequestID) = 0;

	///�����ѯͶ����������ȯ�����ʽ�ͷ��
	virtual int ReqQryCreditFundPosition(CZQThostFtdcQryCreditFundPositionField *pQryCreditFundPosition, int nRequestID) = 0;
protected:
	~CZQThostFtdcTraderApi(){};
};

#endif
