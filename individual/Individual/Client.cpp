#include "pch.h"
#include "Client.h"
#include "stdbool.h"
using namespace System;
using namespace System::Collections;

Client::Client(void)
{
	name = gcnew String("");
	nummer_b = gcnew String("");
	payment_method = gcnew String("");
}

void Client::SetName(String^ Name)
{
	name = Name;
}

void Client::SetNum(String^ Num)
{
	nummer_b = Num;
}

void Client::SetPay(String^ Pay)
{
	payment_method = Pay;
}

String^ Client::GetNameByNum(ArrayList^ Nummers)
{
	bool flag = false;
	for (int i = 0; i < Nummers->Count; i++)
	{
		if (nummer_b->CompareTo(Nummers[i]) == 0)
		{
			flag = true;
			break;
		}
	}
	if (flag)
	{
		return(name);
	}
}

String^ Client::GetNameByPay(ArrayList^ Pay_methods)
{
	bool flag = false;
	for (int i = 0; i < Pay_methods->Count; i++)
	{
		if (payment_method->CompareTo(Pay_methods[i]) == 0)
		{
			flag = true;
			break;
		}
	}
	if (flag)
	{
		return(name);
	}
}

String^ Client::ReturnName(void)
{
	return(name);
}

String^ Client::ReturnNum(void)
{
	return(nummer_b);
}

String^ Client::ReturnPay(void)
{
	return(payment_method);
}