#include "mysort.h"

bool mysort(std::string infilename, int m, std::string outfilename, std::string settingsstring) {
    int lastpart = 0;
    bool mybool = true;
    myTape myTape0(infilename, settingsstring);
    myTape0.changepos(0);
    std::fstream tmpfile("tmp.txt", std::ios::out | std::ios::binary | std::ios::app);
    if (tmpfile.is_open() == false) mybool = false;
    do {
        int c = myTape0.readNumber();
        tmpfile.write((char*)&c, sizeof(c));
    } while (myTape0.moveRight() == true);
    tmpfile.close();
    myTape myTapetmp("tmp.txt", settingsstring);
    for (int j = 0; j < myTapetmp.getsize() - (m - 1); j += m - 1) {
        //находим М-1 наименьших
        std::vector <std::pair<int, int>> myarr;
        myarr.resize(m);
        myTapetmp.changepos(j);
        myarr[0].first = myTapetmp.readNumber();
        myarr[0].second = 0;
        for (int i = 1; i < m; i++) {
            if (myTapetmp.moveRight())
            {
                myarr[i].first = myTapetmp.readNumber();
                myarr[i].second = i;
            }
        }
        std::sort(myarr.begin(), myarr.end());
        int k = m - 1;
        while (myTapetmp.moveRight() == true) {
            k++;
            myarr[m - 1].first = myTapetmp.readNumber();
            myarr[m - 1].second = k;
            std::sort(myarr.begin(), myarr.end());
        }
        //создаем новый Tape, где М наименьших элементов отсортированные и размещенные справа.
        int p = 0;
        myTapetmp.changepos(0);
        std::fstream tmpfile1("tmp1.txt", std::ios::out | std::ios::binary | std::ios::app);
        if (tmpfile1.is_open() == false) mybool = false;
        do {
            int c = myTapetmp.readNumber();
            tmpfile1.write((char*)&c, sizeof(c));
        } while (myTapetmp.moveRight() == true);
        tmpfile1.close();
        myTape myTapetmp1("tmp1.txt", settingsstring);
        myTapetmp1.changepos(j);
        for (int i = 0; i < m - 1; i++) {
            myTapetmp1.writeNumber(myarr[i].first);
            myTapetmp1.moveRight();
        }
        myTapetmp.changepos(j);
        myarr[m - 1].second = -1;
        for (int i = j; i < myTapetmp1.getsize(); i++) {
            std::pair <int, int> p1(myTapetmp.readNumber(), i - j);
            if (std::find(myarr.begin(), myarr.end(), p1) == myarr.end())
            {
                myTapetmp1.writeNumber(p1.first);
                myTapetmp1.moveRight();
            }
            myTapetmp.moveRight();
        }
        myTapetmp1.changepos(0);
        myTapetmp.changepos(0);
        for (int i = 0; i < myTapetmp1.getsize(); i++) {
            myTapetmp.writeNumber(myTapetmp1.readNumber());
            myTapetmp.moveRight();
            myTapetmp1.moveRight();
        }
        std::remove("tmp1.txt");
        lastpart = j + m - 1;
    }
    //Сортируем оставшиеся элементы, которых меньше чем M-1.
    myTapetmp.changepos(lastpart);
    std::vector <int> myarr;
    for (int i = lastpart; i < myTapetmp.getsize(); i++) {
        myarr.push_back(myTapetmp.readNumber());
        myTapetmp.moveRight();
    }
    std::sort(myarr.begin(), myarr.end());
    myTapetmp.changepos(lastpart);
    for (int i = 0; i < myTapetmp.getsize() - lastpart; i++) {
        myTapetmp.writeNumber(myarr[i]);
        myTapetmp.moveRight();
    }
    myTapetmp.changepos(0);
    std::fstream tmpfilefin(outfilename, std::ios::out | std::ios::binary | std::ios::app);
    if (tmpfilefin.is_open() == false) mybool = false;
    do {
        int c = myTapetmp.readNumber();
        tmpfilefin.write((char*)&c, sizeof(c));
    } while (myTapetmp.moveRight() == true);
    return mybool;
}