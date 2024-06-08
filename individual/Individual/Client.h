#pragma once
using namespace System;
using namespace System::Collections;
ref class Client
{
private:
	String^ name;
	String^ nummer_b;
	String^ payment_method;
public:
	Client(void);
	void SetName(String^);
	void SetNum(String^);
	void SetPay(String^);
	String^ GetNameByNum(ArrayList^);
	String^ GetNameByPay(ArrayList^);
	String^ ReturnName(void);
	String^ ReturnNum(void);
	String^ ReturnPay(void);
};