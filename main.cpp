#include <iostream>
#include <conio.h>

using namespace std;

struct Data {
    int nis;
    string nama;
    double absen;
    double tugas;
    double uts;
    double uas;
    double nilaiAkhir;
}siswa[6];

struct Time {
    int hour;
    int minute;
    int second;
};


Data getData(Data, int);
void displayData(Data, int);
Time countTime(Time);
void showTime(Time);


int main()
{
    Data a;
    int n;
    Time time;

    cout << "==================="<< endl;
    cout << "Briliando Simarmata"<< endl;
    cout << "1610631170059"<< endl;
    cout << "==================="<< endl;
    cout << endl << endl;

    cout << "No.1 Program Hitung Nilai Akhir" << endl;
    cout << endl;

    do
    {
        cout << "Masukkan banyak siswa (maksimal 5): "; cin >> n;
        cout << endl;
    }
    while (n > 5);

    a = getData(a,n);
    displayData(a,n);
    time = countTime(time);
    showTime(time);

    return 0;
}

Data getData(Data a, int n)
{
    for (int i = 0; i < n; i++)
        {
            cout << "Data Siswa " << i+1 << endl;
            cout << "Masukkan NIS: "; cin >> siswa[i].nis;
            cout << "Masukkan Nama: "; cin >> siswa[i].nama;
            cout << "Masukkan Nilai Absen: "; cin >> siswa[i].absen;
            cout << "Masukkan Nilai Tugas: "; cin >> siswa[i].tugas;
            cout << "Masukkan Nilai UTS: "; cin >> siswa[i].uts;
            cout << "Masukkan Nilai UAS: "; cin >> siswa[i].uas;
            siswa[i].nilaiAkhir = siswa[i].absen*0.1 + siswa[i].tugas*0.2 + siswa[i].uts*0.3 + siswa[i].uas*0.4;
            cout << endl;
        }


    return siswa[n];
}

void displayData(Data a, int n)
{
    for (int i = 0; i < n; i++)
        {
            cout << "Data Siswa " << i+1 << endl;
            cout << "NIS          : " << siswa[i].nis << endl;
            cout << "Nama         : " << siswa[i].nama << endl;
            cout << "Nilai Absen  : " << siswa[i].absen << endl;
            cout << "Nilai Tugas  : " << siswa[i].tugas << endl;
            cout << "Nilai UTS    : " << siswa[i].uts << endl;
            cout << "Nilai UAS    : " << siswa[i].uas << endl;
            cout << "Nilai Akhir  : " << siswa[i].nilaiAkhir << endl;

            if (siswa[i].nilaiAkhir > 85)
            {
                cout << "GRADE A" << endl;
            }
            else if (siswa[i].nilaiAkhir > 70 && siswa[i].nilaiAkhir <= 85)
            {
                cout << "GRADE B" << endl;
            }
            else if (siswa[i].nilaiAkhir > 55 && siswa[i].nilaiAkhir <= 70)
            {
                cout << "GRADE C" << endl;
            }
            else if (siswa[i].nilaiAkhir > 40 && siswa[i].nilaiAkhir <= 55)
            {
                cout << "GRADE D" << endl;
            }
            else
            {
                cout << "GRADE E" << endl;
            }

            cout << endl;

        }
        getch();

}

Time countTime(Time time)
{
    system("cls");
    Time indo;
    Time otherCountry;
    int timeResult;
    int minute;

    cout << "No.2 Program Hitung Perbedaan Waktu" << endl << endl;

    do {
        cout << "Masukkan waktu di Indonesia (ex: 24 00 00): ";
        cin >> indo.hour >> indo.minute >> indo.second;
        cout << "Masukkan waktu di Negara Lain (ex: 24 00 00): ";
        cin >> otherCountry.hour >> otherCountry.minute >> otherCountry.second;
        if (indo.hour > 24 || otherCountry.hour > 24 || indo.minute > 60 || otherCountry.minute > 60 || indo.second > 60 || otherCountry.second > 60)
        {
            cout << "Format waktu yang dimasukkan salah. Ulangi lagi!" << endl << endl;
        }
    }
    while (indo.hour > 24 || otherCountry.hour > 24 || indo.minute > 60 || otherCountry.minute > 60 || indo.second > 60 || otherCountry.second > 60);


    if (indo.hour > otherCountry.hour)
    {
        timeResult = indo.hour - otherCountry.hour;
        timeResult = (timeResult*60 + indo.minute) - otherCountry.minute;
        timeResult = (timeResult*60 + indo.second) - otherCountry.second;
        if (timeResult/60 >= 60)
        {
            time.hour = timeResult/3600;
            if ((timeResult%3600) >= 60)
            {

                time.minute = (timeResult%3600)/60;
                time.second = (timeResult%3600)%60;
            }
            else
            {
                time.minute = 0;
                time.second = timeResult%3600;
            }
        }
        else
        {
            time.hour = 0;
            time.minute = timeResult/60;
            time.second = timeResult%60;
        }

    }
    else
    {
        timeResult = otherCountry.hour - indo.hour;
        timeResult = (timeResult*60 + otherCountry.minute) - indo.minute;
        timeResult = (timeResult*60 + otherCountry.second) - indo.second;
        if (timeResult/60 >= 60)
        {
            time.hour = timeResult/3600;
            if ((timeResult%3600) >= 60)
            {

                time.minute = (timeResult%3600)/60;
                time.second = (timeResult%3600)%60;
            }
            else
            {
                time.minute = 0;
                time.second = timeResult%3600;
            }
        }
        else
        {
            time.hour = 0;
            time.minute = timeResult/60;
            time.second = timeResult%60;
        }

    }

    return time;

}

void showTime (Time time)
{
    cout << endl;
    if (time.hour >= 1)
    {
        cout << "Perbedaan waktu adalah "<< time.hour << " jam, " << time.minute << " menit, " << time.second << " detik." << endl;
    }
    else
    {
        cout << "Perbedaan waktu adalah "<< time.minute << " menit, " << time.second << " detik." << endl;
    }
}
