#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    //dosyadan verileri okuyur
    string A[25][25];
    ifstream fin("Ada.txt");
    string line;
    int i = 0, j = 0;
    while (getline(fin, line))
    {
        stringstream linestream(line);
        string value;

        while (getline(linestream, value, ','))
        {

            A[i][j] = value; //dosyadan 2.boyutlu bir diziye atar
            j++;
        }

        j = 0;
        i++;
    }
    fin.close();

    cout << endl;
    string B[25][25], C[25][25];

    for (i = 0; i < 25; i++)
    {
        for (j = 0; j < 25; j++)
        {
            B[i][j] = A[i][j]; //A dizi degistirleyecegme icin B diziye atar
            C[i][j] = A[i][j]; //A dizi degistirleyecegme icin C diziye atar
        }
    }

    string S[4], Yarismaciler[4];
    S[0] = "Y";
    S[1] = "Z";
    S[2] = "S";
    S[3] = "P";
    int m[500], n[500], v[500], H[4], Q[4], r, c = 0, as, d;
    bool z, finsh, k;
    string l[500];
    for (int f = 0; f < 25; f++)
    {

        if (A[f][0] != "0")
        {
            Yarismaciler[c] = A[f][0];
            for (i = 0; i < 25; i++)
            {
                for (j = 0; j < 25; j++)
                {
                    A[i][j] = B[i][j];
                    C[i][j] = B[i][j];
                }
            }

            m[500];
            n[500];
            v[500] = {0};
            r = 0;
            as = 0;
            i = f, d = 0;
            z = false;
            finsh = false, k = false;

            cout << "Yarismaci :" << A[f][0] << "  Maden aran : " << S[c] << endl;

            j = 0;
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            while (r >= 0)
            {

                while (A[i][j + 1] == "1" || A[i][j + 1] == "Y" || A[i][j + 1] == "Z" || A[i][j + 1] == "P" || A[i][j + 1] == "S" || A[i][j + 1] == "E" || A[i][j - 1] == "1" || A[i][j - 1] == "Y" || A[i][j - 1] == "Z" || A[i][j - 1] == "P" || A[i][j - 1] == "S" || A[i][j - 1] == "E" || A[i - 1][j] == "1" || A[i - 1][j] == "Y" || A[i - 1][j] == "Z" || A[i - 1][j] == "P" || A[i - 1][j] == "S" || A[i - 1][j] == "E" || A[i + 1][j] == "1" || A[i + 1][j] == "Y" || A[i + 1][j] == "Z" || A[i + 1][j] == "P" || A[i + 1][j] == "S" || A[i + 1][j] == "E")
                {

                    if (z == true)
                        r++;
                    while (A[i][j + 1] == "1" || A[i][j + 1] == "Y" || A[i][j + 1] == "Z" || A[i][j + 1] == "P" || A[i][j + 1] == "S") //saga aran
                    {
                        if (A[i][j + 1] == "E")
                        {
                            m[r] = i;
                            n[r] = j + 1;
                            l[r] = "sag";
                            r++;
                            finsh = true;
                            break;
                        }
                        else if (A[i][j - 1] == "E")
                        {
                            m[r] = i;
                            n[r] = j - 1;
                            l[r] = "sol";
                            r++;
                            finsh = true;
                            break;
                        }
                        else if (A[i + 1][j] == "E")
                        {
                            m[r] = i + 1;
                            n[r] = j;
                            l[r] = "yukari";
                            r++;
                            finsh = true;
                            break;
                        }
                        else if (A[i - 1][j] == "E")
                        {
                            m[r] = i - 1;
                            n[r] = j;
                            l[r] = "asagi";
                            r++;
                            finsh = true;
                            break;
                        }

                        j = j + 1;

                        if (A[i][j] != S[c])
                        {
                            v[r] = 0;
                        }
                        else
                        {
                            v[r] = 10;
                        }

                        A[i][j] = ">";

                        m[r] = i;
                        n[r] = j;
                        l[r] = "sag";

                        //cout<<r<<" = "<<m[r]<<"  "<<n[r]<<"  "<<l[r]<<"  "<<v[r]<<endl;
                        r++;
                    }
                    while (A[i][j - 1] == "1" || A[i][j - 1] == "Y" || A[i][j - 1] == "Z" || A[i][j - 1] == "P" || A[i][j - 1] == "S") //sola aran
                    {
                        if (A[i][j + 1] == "E")
                        {
                            m[r] = i;
                            n[r] = j + 1;
                            l[r] = "sag";
                            r++;
                            finsh = true;
                            break;
                        }
                        else if (A[i][j - 1] == "E")
                        {
                            m[r] = i;
                            n[r] = j - 1;
                            l[r] = "sol";
                            r++;
                            finsh = true;
                            break;
                        }
                        else if (A[i + 1][j] == "E")
                        {
                            m[r] = i + 1;
                            n[r] = j;
                            l[r] = "yukari";
                            r++;
                            finsh = true;
                            break;
                        }
                        else if (A[i - 1][j] == "E")
                        {
                            m[r] = i - 1;
                            n[r] = j;
                            l[r] = "asagi";
                            r++;
                            finsh = true;
                            break;
                        }

                        j = j - 1;
                        if (A[i][j] != S[c])
                        {
                            v[r] = 0;
                        }
                        else
                        {
                            v[r] = 10;
                        }

                        A[i][j] = "<";
                        m[r] = i;
                        n[r] = j;
                        l[r] = "sol";

                        //cout<<r<<" = "<<m[r]<<"  "<<n[r]<<"  "<<l[r]<<"  "<<v[r]<<endl;
                        r++;
                    }

                    while (A[i + 1][j] == "1" || A[i + 1][j] == "Y" || A[i + 1][j] == "Z" || A[i + 1][j] == "P" || A[i + 1][j] == "S") //asagiya aran
                    {
                        if (A[i][j + 1] == "E")
                        {
                            m[r] = i;
                            n[r] = j + 1;
                            l[r] = "sag";
                            r++;
                            finsh = true;
                            break;
                        }
                        else if (A[i][j - 1] == "E")
                        {
                            m[r] = i;
                            n[r] = j - 1;
                            l[r] = "sol";
                            r++;
                            finsh = true;
                            break;
                        }
                        else if (A[i + 1][j] == "E")
                        {
                            m[r] = i + 1;
                            n[r] = j;
                            l[r] = "yukari";
                            r++;
                            finsh = true;
                            break;
                        }
                        else if (A[i - 1][j] == "E")
                        {
                            m[r] = i - 1;
                            n[r] = j;
                            l[r] = "asagi";
                            r++;
                            finsh = true;
                            break;
                        }

                        i = i + 1;

                        if (A[i][j] != S[c])
                        {
                            v[r] = 0;
                        }
                        else
                        {
                            v[r] = 10;
                        }

                        A[i][j] = "v";
                        m[r] = i;
                        n[r] = j;
                        l[r] = "asagi";
                        r++;
                    }

                    while (A[i - 1][j] == "1" || A[i - 1][j] == "Y" || A[i - 1][j] == "Z" || A[i - 1][j] == "P" || A[i - 1][j] == "S") //yukariya aran
                    {
                        if (A[i][j + 1] == "E")
                        {
                            m[r] = i;
                            n[r] = j + 1;
                            l[r] = "sag";
                            r++;
                            finsh = true;
                            break;
                        }
                        else if (A[i][j - 1] == "E")
                        {
                            m[r] = i;
                            n[r] = j - 1;
                            l[r] = "sol";
                            r++;
                            finsh = true;
                            break;
                        }
                        else if (A[i + 1][j] == "E")
                        {
                            m[r] = i + 1;
                            n[r] = j;
                            l[r] = "yukari";
                            r++;
                            finsh = true;
                            break;
                        }
                        else if (A[i - 1][j] == "E")
                        {
                            m[r] = i - 1;
                            n[r] = j;
                            l[r] = "asagi";
                            r++;
                            finsh = true;
                            break;
                        }

                        i = i - 1;
                        if (A[i][j] != S[c])
                        {
                            v[r] = 0;
                        }
                        else
                        {
                            v[r] = 10;
                        }

                        A[i][j] = "^";
                        m[r] = i;
                        n[r] = j;
                        l[r] = "yukari";
                        r++;
                    }

                    z = false;
                    if (finsh)
                        break;
                }
                if (finsh)
                    break;

                //cout<<"========="<<endl;
                r--;
                z = true;
                i = m[r];
                j = n[r];
                v[r] = 0;
                //cout<<r<<" = "<<m[r]<<"  "<<n[r]<<"  "<<v[r]<<endl;//maliyat
                //cout<<endl;
                as++;
                //cout<<" ------- "<<as<<" ---------- "<<endl;
            }
            v[r - 1] = 0;
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            cout << "Labirentte hazine aramak icin tum adimlar : " << endl
                 << "sag : >" << endl
                 << "sol : <" << endl
                 << "yukari : ^" << endl
                 << "asagi : v" << endl;

            cout << endl;

            for (i = 0; i < 25; i++)
            {
                for (j = 0; j < 25; j++)
                {
                    cout << A[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;

            cout << "Yarismaci icin odullerin alinmasiyla hazineye giden yol : " << endl;
            cout << endl;
            string file_isimi;
            if (c == 0)
            {
                file_isimi = "P1adim.txt";
            }
            else if (c == 1)
            {
                file_isimi = "P2adim.txt";
            }
            else if (c == 2)
            {
                file_isimi = "P3adim.txt";
            }
            else if (c == 3)
            {
                file_isimi = "P4adim.txt";
            }
            cout << file_isimi;
            cout << endl;
            ofstream file_;
            file_.open(file_isimi);
            cout << "(Begin)";
            file_ << "(Begin)";
            i = 0;
            while (i < r)
            {
                v[i] = v[i] + v[i - 1];

                C[m[i]][n[i]] = ".";
                if (l[i] != l[i - 1])
                {

                    cout << endl
                         << l[i];
                    file_ << endl
                          << l[i];
                    cout << " => (" << m[i] << " , " << n[i] << " , " << v[i] << ")";
                    file_ << " => (" << m[i] << " , " << n[i] << " , " << v[i] << ")";
                }
                else
                {
                    cout << " => (" << m[i] << " , " << n[i] << " , " << v[i] << ")";
                    file_ << " => (" << m[i] << " , " << n[i] << " , " << v[i] << ")";
                }

                H[c] = v[i];
                i++;
            }

            cout << endl
                 << "(Exit)";
            file_ << endl
                  << "(Exit)";
            file_.close();

            cout << endl;
            cout << endl;
            cout << "Hazineye giden yol bir grafikle gosterilir : " << endl
                 << endl;

            for (i = 0; i < 25; i++)
            {
                for (j = 0; j < 25; j++)
                {
                    cout << C[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
            cout << endl;
            Q[c] = r;

            cout << "Hazineye dogru attigi adim sayisi   :   ( " << Q[c] << " ) " << endl;
            cout << "puan sayisi   :   ( " << H[c] << " ) " << endl;
            c++;

            cout << "------------------------------------------------------------" << endl;
            cout << endl;
        }
    }
    int p, temp, x, odusayitemp;
    string yar, odu;
    temp = Q[0];
    for (i = 0; i < c; i++)
    {

        if (temp >= Q[i])
        {
            temp = Q[i];
            x = i;
        }
    }
    ofstream file_Sonuc;
    file_Sonuc.open("Sonuc.txt");
    H[x] = H[x] + 15;
    cout << "en kisa yol icin " << Yarismaciler[x] << " Yarismaci puan sayisi   :   ( " << H[x] << " ) " << endl;
    file_Sonuc << "en kisa yol icin " << Yarismaciler[x] << " Yarismaci puan sayisi   :   ( " << H[x] << " ) " << endl;
    for (i = 0; i < c; i++)
    {
        for (j = i; j < c; j++)
        {

            if (Q[i] >= Q[j])
            {
                temp = Q[i];
                Q[i] = Q[j];
                Q[j] = temp;
                odu = S[i];
                S[i] = S[j];
                S[j] = odu;
                yar = Yarismaciler[i];
                Yarismaciler[i] = Yarismaciler[j];
                Yarismaciler[j] = yar;
                odusayitemp = H[i];
                H[i] = H[j];
                H[j] = odusayitemp;
            }
        }
    }

    cout << "sira"
         << "  Yarismaci"
         << "  odul"
         << "  adim"
         << "  puan" << endl;
    file_Sonuc << "sira"
               << "  Yarismaci"
               << "  odul"
               << "  adim"
               << "  puan" << endl;
    for (j = 0; j < c; j++)
    {
        cout << j + 1 << ".    " << Yarismaciler[j] << "          " << S[j] << "      " << Q[j] << "    " << H[j] << endl;
        file_Sonuc << j + 1 << ".    " << Yarismaciler[j] << "          " << S[j] << "      " << Q[j] << "    " << H[j] << endl;
    }
    temp = H[0];
    for (i = 0; i < c; i++)
    {

        if (temp <= H[i])
        {
            temp = H[i];
            x = i;
        }
    }
    cout << "en yuksik puan icin ( " << Yarismaciler[x] << " )kazandi , Yarismaci puan sayisi   :   ( " << H[x] << " ) " << endl;
    file_Sonuc << "en yuksik puan icin ( " << Yarismaciler[x] << " )kazandi , Yarismaci puan sayisi   :   ( " << H[x] << " ) " << endl;
    file_Sonuc.close();

    return 0;
}
