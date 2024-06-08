#include "pch.h"
#include "stdio.h"
#include "Client.h"
#include <iostream>
#include <locale.h>
#include < string.h >

using namespace System;
using namespace System::Collections;

void print_comands()
{
    printf("Выбирете команду:\n");
    printf("1 = добавление нового клиента\n");
    printf("2 = поиск нужных клиентов по номерам билетов\n");
    printf("3 = поиск нужных клиентов по способу оплаты через Интернет\n");
    printf("4 = вывести список всех клиентов\n");
    printf("0 = закончить программу\n");
}

int checkErrorComand(char str[999])
{
    int i = 0;
    int error = 0;
    while (str[i] != '\0')
    {
        if (str[i] > '4' || str[i] < '0')
        {
            error = 1;
            break;
        }
        i++;
    }
    return error;
}

int checkErrorNum(String^ str)
{
    int i = 0;
    int error = 0;
    while (i < str->Length)
    {
        if (str[i] > '9' || str[i] < '0')
        {
            error = 1;
            break;
        }
        i++;
    }
    return error;
}

int checkErrorNamePay(String^ str)
{
    int i = 0;
    int error = 0;
    while (i < str->Length)
    {
        if (str[i] < '9' && str[i] > '0')
        {
            error = 1;
            break;
        }
        i++;
    }
    return error;
}

int main(array<System::String ^> ^args)
{
    ArrayList^ Clients = gcnew ArrayList();
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    long antwort = -1;
    char srt_ant[999], str_num[999];
    while (antwort != 0)
    {
        print_comands();
        scanf("%s", srt_ant);
        if (checkErrorComand(srt_ant) != 1)
        {
            antwort = strtol(srt_ant, NULL, 10);
        }
        else
        {
            printf("Ошибка! Введена буква или номер команды не сущетсвует!");
            antwort = -1;
        }
        if (antwort == 1)
        {
            Client^ NewClient = gcnew Client;
            printf("Введите имя клиента: ");
            String^ NameСlient = Console::ReadLine();
            while (checkErrorNamePay(NameСlient) == 1)
            {
                printf("Ошибка! Имя может содержать только буквы!\n");
                NameСlient = Console::ReadLine();
            }
            printf("Введите номер билета клиента: ");
            String^ NumСlient = Console::ReadLine();
            while (checkErrorNum(NumСlient) == 1)
            {
                printf("Ошибка! Номер билета может содержать только цифры!\n");
                NumСlient = Console::ReadLine();
            }
            printf("Введите способ оплаты через Интернет клиента: ");
            String^ PayСlient = Console::ReadLine();
            while (checkErrorNamePay(PayСlient) == 1)
            {
                printf("Ошибка! Способ оплаты через Интернет может содержать только буквы!\n");
                PayСlient = Console::ReadLine();
            }
            NewClient->SetName(NameСlient);
            NewClient->SetNum(NumСlient);
            NewClient->SetPay(PayСlient);
            Clients->Add(NewClient);
        }
        if (antwort == 2 || antwort == 3)
        {
            ArrayList^ Serch = gcnew ArrayList();
            ArrayList^ Find = gcnew ArrayList();
            String^ NewFind = gcnew String("");
            while (true)
            {
                printf("Вводите номера билетов или способы покупки через интернет(0 - если ввод окончен)");
                NewFind = Console::ReadLine();
                if (NewFind == "0")
                {
                    break;
                }
                Serch->Add(NewFind);
            }
            if (antwort == 2)
            {
                for (int i = 0; i < Clients->Count; i++)
                {
                    Client^ a = (Client^)Clients[i];
                    if (a->GetNameByNum(Serch))
                    {
                        Find->Add(a);
                    }
                }
            }
            if (antwort == 3)
            {
                for (int i = 0; i < Clients->Count; i++)
                {
                    Client^ a = (Client^)Clients[i];
                    if (a->GetNameByPay(Serch))
                    {
                        Find->Add(a);
                    }
                }
            }
            if (Find->Count == 0)
            {
                printf("Таких клиентов нет!\n");
            }
            else
            {
                for (int i = 0; i < Find->Count; i++)
                {
                    printf("-------------\n");
                    Client^ a = (Client^)Find[i];
                    System::Console::WriteLine(a->ReturnName());
                    System::Console::WriteLine(a->ReturnNum());
                    System::Console::WriteLine(a->ReturnPay());
                }
            }
        }
        if (antwort == 4)
        {
            for (int i = 0; i < Clients->Count; i++)
            {
                printf("-------------\n");
                Client^ a = (Client^)Clients[i];
                printf("Клиент: ");
                System::Console::WriteLine(a->ReturnName());
                printf("Номер билета: ");
                System::Console::WriteLine(a->ReturnNum());
                printf("Способ оплаты: ");
                System::Console::WriteLine(a->ReturnPay());
            }
        }
    }
}
