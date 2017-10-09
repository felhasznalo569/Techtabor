#include <bits/stdc++.h>
#include <windows.h>


using namespace std;

//mutat: megjeleníti a kártyát. Windows-on valóban a színek (kõr, treff,...) kis ikonjai jelennek meg.

void mutat (int kartya1)
{
char a[4] = {3,4,5,6};
if (kartya1!=0)
{
if (kartya1/10==11) cout<<"J";
else if (kartya1/10==12) cout<<"D";
else if (kartya1/10==13) cout<<"K";
else if (kartya1/10==1) cout<<"A";
else cout<<(kartya1/10);
for(int c=1; c<=4;c++)
{
    if (kartya1%10==c)
    {
        cout<<a[c-1];
    }
}
cout<<" ";
}
}

//rakas: kiírja, amit az ellenfél (gép) mondana

void rakas (int rakas1)
{
    for(int i=1; i<14; i++)
    if(rakas1/10==i)
    {
    if (rakas1/10==11) cout<<"'A rakasom: J'"<<" (gep)"<<endl;
    else if (rakas1/10==12) cout<<"'A rakasom: D'"<<" (gep)"<<endl;
    else if (rakas1/10==13) cout<<"'A rakasom: K'"<<" (gep)"<<endl;
    else if (rakas1/10==1) cout<<"'A rakasom: A'"<<" (gep)"<<endl;
    else cout<<"'A rakasom: "<<(rakas1/10)<<"' (gep)"<<endl;
    }
}

//rakasod: megjeleníti egy kártya értékét

void rakasod (int rakasod1)
{
    for(int i=1; i<14; i++)
    if(rakasod1/10==i)
    {
    if (rakasod1/10==11) cout<<"J";
    else if (rakasod1/10==12) cout<<"D";
    else if (rakasod1/10==13) cout<<"K";
    else if (rakasod1/10==1) cout<<"A";
    else cout<<(rakasod1/10);
    }
}

/*int mennyivankezben (int mibol, int kartyak[])
{
    int mennyi=0;
    for(int i=0; i<26; i++)
    {
        if (kartyak[i]/10==mibol) mennyi++;
    }
    return mennyi;
}

int mennyimentle (int mibol1, int kartyak1[])
{
    int mennyi=0;
    for(int i=0; i<52; i++)
    {
        if (kartyak1[i]/10==mibol1) mennyi++;
    }
    return mennyi;
}*/

int main()
{

    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);

    string bloffe;
    int mennyi, mennyi1, mibol, mibol1, elselap, p,q,m,r,s,hanyadik,kor,vesztes, vesztesgep, vesztesjatekos,g,rak,j,f,k,t;
    int jatek[53]; //kártyák, amelyek a játszmában kijátszásra kerülnek
    int kartya [52]; //a pakli

    //a pakli feltöltése kártyákkal. j a kártya színe, i az értéke.

    for(int i=1; i<=13; i++)
    {
        for(j=1; j<=4; j++)
        {
            kartya[((i-1)*4)+j-1]=j+10*i;
        }
    }

    //a két játékos

    int jatekos[13], gep[13];

    //pakli megkeverése

    random_shuffle(&kartya[0], &kartya[52]);

    //osztas

    for(int a=0; a<=(12); a++)
    {
        jatekos[a]=kartya[a];
    }

    for(int b=0; b<=(12); b++)
    {
        gep[b]=kartya[b+14];
    }

    //a lapok rendezése a pakliban, és a két játékos kezében

    sort(&jatekos[0], &jatekos[13]);
    sort(&gep[0], &gep[13]);
    sort(&kartya[0], &kartya[52]);

    cout<<"A JATEK: BLOFF"<<endl;
    cout<<endl;
    cout<<"SZABALYZAT: A Jatekot ket jatekos jatssza, jelen esetben a felhasznalo es a szamitogep. Az 52 lapbol allo franciakartya-paklit megkeverjuk, majd mindket jatekos 13 kartyat kap. Az egyik jatekos letesz egy kartyat a kezebol, es mondja: Az en rakasom: asz. Ezutan a masodik jatekos kovetkezik, letesz egy kartyat a kezebol, es mondja: Ketto. Majd ismet az elso jatekos kovetkezik, letesz egy lapot, mondja: Harom. Ez igy folytatodik, amig valamelyik jatekos azt nem mondja a masik rakasa utan, hogy Bloff. Ekkor felforditjuk az elozo jatekos altal az iment lerakott lapot, es ha annak erteke megegyezik a mondassal, a bemondo maga melle teszi az osszegyult kartyakat, hza azonban az utolso kartya erteke nem egyezik meg a bemondotteval, akkor a masik jatekos valoban bloffolt, igy o kapja meg a kartyacsomagot. A jatek ezutan ugyanonnan folytatodik. Az a jatekos nyer, aki a jatek vegeig (amikor mindenki kezebol elfogytak a lapok), kevesebb lapot gyujtott be maga melle.";
    cout<<endl;
    cout<<endl;
    cout<<"A lapok a keveres utan kiosztasra kerultek. A te lapjaid:  "<<endl;
    for (int x=0; x<13; x++) mutat(jatekos[x]);
    cout<<endl;
    cout<<endl;
    vesztes=0;
    vesztesgep=0;
    vesztesjatekos=0;



    for(kor=0; kor<26; kor=kor+2)
    {
    //összesen 26 rakás
    //a gép rak

    if(kor==0) //az első rakás
    {
        rakas(kartya[(4*kor)%52]);
        jatek[kor]=gep[kor];
        gep[kor]=0;
        vesztes++;
    }

    else
    {
        f=0;
        k=0;
        t=0;
        for(rak=0; rak<12; rak++)
        {
            if(gep[rak]/10==(kartya[(4*(kor-1)%52)]/10)) f++;
        }
        while (k<(kor))
        {
            if (jatek[k]/10==(kartya[(4*(kor-1)%52)]/10)) f++;
            k=k+2;
        }
        if (f==0 && rand()%7==0) t=1;
        if (f==1 && rand()%4==0) t=1;
        if (f==2 && rand()%2==0) t=1;
        if (f==3 && rand()%3!=0) t=1;
        if (f==4) t=1;
        if (t==1)
        {
            cout<<"BLOFF! (gep) "<<endl;
            mutat(jatek[kor-1]);
        if (jatek[kor-1]/10!=(kartya[(4*(kor-1)%52)]/10))
        {
            cout<<"-t raktad le, tenyleg bloffoltel. Elveszed az eddig lerakott "<<vesztes<<" kartyat."<<endl;
            cout<<endl;
            vesztesjatekos=vesztesjatekos+vesztes;
            cout<<"Te eddig "<<vesztesjatekos<<" lapot vittel, a gep pedig "<<vesztesgep<<"-t. "<<endl;
            vesztes=0;

        }
        else
        {
            cout<<"-t raktad le, nem bloffoltel. A gep elveszi az eddig lerakott "<<vesztes<<" kartyat."<<endl;
            cout<<endl;
            vesztesgep=vesztesgep+vesztes;
            cout<<"Te eddig "<<vesztesjatekos<<" lapot vittel, a gep pedig "<<vesztesgep<<"-t. "<<endl;
            vesztes=0;
        }
        }
        vesztes++; //a gep lerak egy lapot
        g=0;
        while (gep[g]/10!=(kartya[((4*kor))%52]/10) && g<13) g++; //keres egy olyan lapot, ami jó lenne
        if(gep[g]/10==(kartya[((4*kor))%52]/10)) //ha talált ilyet, lerakja
        {


            rakas(kartya[(4*kor)%52]);
            jatek[kor]=gep[g];
            gep[g]=0;
        }
        else //ha nem talált, akkor megnézi, miből van több ugyanolyanja, és ha talál ilyet, abból lerakja a legnagyobbat
        {

        rakas(kartya[(4*kor)%52]);
        mennyi1=0;
        elselap=0;
        for(mibol=13; mibol>1; mibol=mibol-1)
        {
        mennyi=0;
        for(p=0; p<13; p++)
        {
            if ((gep[p]/10)==mibol)
            {
            mennyi++;
            elselap=gep[p];

            }

        }
        if (mennyi>=mennyi1)
        {
             mennyi1=mennyi;
             jatek[kor]=elselap;


        }
        }


        for(q=0; q<13; q++)
        {
            if (gep[q]==elselap) gep[q]=0;

        }

        }


    }


    cout<<endl; //a játékos következik
    cout<<"Bemondod, hogy BLOFF? (i/n) ";
    cin>>bloffe;
    cout<<endl;
    if (bloffe=="i")
    {
        cout<<"BLOFF! (te)";
        cout<<endl;
        cout<<"A gep valojaban ezt a lapot rakta: ";
        mutat(jatek[kor]);
        cout<<endl;
        if (jatek[kor]/10!=(kartya[(4*kor)%52])/10)
        {
            cout<<"Tenyleg bloffolt. A gep elveszi az eddig lerakott "<<vesztes<<" kartyat."<<endl;
            vesztesgep=vesztesgep+vesztes;
            cout<<"Te eddig "<<vesztesjatekos<<" lapot vittel, a gep pedig "<<vesztesgep<<"-t. "<<endl;
            vesztes=0;

        }
        else
        {
            cout<<"Nem bloffolt. Te veszed el az eddig lerakott "<<vesztes<<" kartyat."<<endl;
            vesztesjatekos=vesztesjatekos+vesztes;
            cout<<"Te eddig "<<vesztesjatekos<<" lapot vittel, a gep pedig "<<vesztesgep<<"-t. "<<endl;
            vesztes=0;
        }
    }
    vesztes++;
    cout<<endl;
    cout<<"A te kezedben a kovetkezo kartyak vannak: "<<endl;
    for (m=0; m<13; m++) mutat(jatekos[m]);
    cout<<endl;
    cout<<endl;
    //a felhasználó rak
    cout<<"Azt kell mondanod, hogy a te rakasod ";
    rakasod(kartya[(4*(kor+1))%52]);
    cout<<". "<<endl;
    cout<<"A lapjaid kozul HANYADIKAT szeretned letenni? ";
    cin>>hanyadik;
    r=0;
    s=0;
    while(s<hanyadik)
    {
        if (jatekos[r]>0)
        {
            s++;
        }
        r++;

    }
    jatek[kor+1]=jatekos[r-1];
    cout<<"Ezt raktad le: ";
    mutat(jatek[kor+1]);
    cout<<endl;
    cout<<endl;
    jatekos[r-1]=0;


    }

    cout<<"BLOFF! (gep) "<<endl; //az utolsó körben a gép mindenképp bemonja, hogy blöff
            mutat(jatek[kor-1]);
        if (jatek[kor-1]/10!=(kartya[(4*(kor-1)%52)]/10))
        {
            cout<<"-t raktad le, tenyleg bloffoltel. Elveszed az eddig lerakott "<<vesztes<<" kartyat."<<endl;
            cout<<endl;
            vesztesjatekos=vesztesjatekos+vesztes;
            cout<<"Te eddig "<<vesztesjatekos<<" lapot vittel, a gep pedig "<<vesztesgep<<"-t. "<<endl;
            vesztes=0;

        }
        else
        {
            cout<<"-t raktad le, nem bloffoltel. A gep elveszi az eddig lerakott "<<vesztes<<" kartyat."<<endl;
            cout<<endl;
            vesztesgep=vesztesgep+vesztes;
            cout<<"Te eddig "<<vesztesjatekos<<" lapot vittel, a gep pedig "<<vesztesgep<<"-t. "<<endl;
            vesztes=0;
        }

    //jatek vége

    cout<<endl;
    cout<<"A jateknak vege. A gep osszesen "<<vesztesgep<<" lapot vitt el, te pedig "<<vesztesjatekos<<"-t. "<<endl;
    cout<<endl;
    if (vesztesgep>vesztesjatekos) cout<<"NYERTEL! ";
    else if (vesztesgep<vesztesjatekos) cout<<"VESZTETTEL! ";
    else cout<<"DONTETLEN! ";
    cout<<endl;
    cin.ignore ();
    cin.get();


    return 0;
}
