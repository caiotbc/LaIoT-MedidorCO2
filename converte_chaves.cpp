#include <iostream>
#include <string>

using namespace std;

#define OTAA 0

int main()
{
    string dev_eui, app_eui, app_key, abp_appskey, abp_nwkskey;
    //cin >> dev_eui;
    dev_eui = "1ceb9da836c4ae3f";
    app_eui = "5b17cfc3d32248c6";
    app_key = "0bb480f284fea8d061ddd922f50545dd";

    abp_nwkskey = "4990f4c7105cc5c648660a5d6da60415";
    abp_appskey = "173c8a61efa1cd9faf73505dd4834b1f";

    if(OTAA==1)
    {
            cout << "APP KEY: " << endl;
        for(int i = 0 ; i < app_key.length(); i++)
        {
            if(i%2==0)
                cout << "0x" << (char)(isalpha(app_key[i]) ? toupper(app_key[i]) : app_key[i]);
            else
                cout << (char)(isalpha(app_key[i]) ? toupper(app_key[i]) : app_key[i]) << ", ";
        }
        for(int i = 0 ; i < dev_eui.length() ; i++)
        {
            dev_eui[i] = toupper(dev_eui[i]);
            app_eui[i] = toupper(app_eui[i]);
        }
        cout << "\nDEV EUI : " << endl;
        for (int i = 17 ; i >= 0; i-=2)
        {
            cout<<"0x" << dev_eui[i-1]<<dev_eui[i] << ", ";
        }
        cout << "\nAPP EUI : " << endl;
        for (int i = 17 ; i >= 0; i-=2)
        {
            cout<<"0x" <<app_eui[i-1]<<app_eui[i] << ", ";
        }
        cout << endl;
    }
    else
    {
        for(int i = 0 ; i < abp_nwkskey.length() ; i++)
        {
            abp_nwkskey[i] = toupper(abp_nwkskey[i]);
            abp_appskey[i] = toupper(abp_appskey[i]);
        }
        cout << "\nAPP KEY: " << endl;
        for (int i = 0; i <  abp_appskey.length(); i+=2)
        {
            cout<<"0x" << abp_appskey[i]<<abp_appskey[i+1] << ", ";
        }
        cout << "\nNETWORK KEY : " << endl;
        for (int i = 0; i <  abp_appskey.length(); i+=2)
        {
            cout<<"0x" <<abp_nwkskey[i]<<abp_nwkskey[i+1] << ", ";
        }
        cout << endl;
    }
    return 0;
}

