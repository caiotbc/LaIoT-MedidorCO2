#include <iostream>
#include <string>

using namespace std;

int main()
{
    string dev_eui, app_eui, app_key;
    //cin >> dev_eui;
    dev_eui = "1ceb9da836c4ae3f";
    app_eui = "1a22dcebd4ef20ae";
    app_key = "580d63f231c1a7538e92bfdde7196fc9";
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
    return 0;
}

