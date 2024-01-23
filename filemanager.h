#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
using namespace std;

class filemanager {
public:
    void saveusertofile(const string& userData);
    void savemenuitemtofile(const string& menuItemData);
    void saveordertofile(const string& orderData);
    void saveeditedordertofile(const string& orderData);
    void saveratingtofile(const string& ratingData);
    void savepayementtofile(const string& paymentData);

    void displayuser_fromfile(const string& fileName);
    void displaymenuitem_fromfile(const string& fileName);
    void displayorder_fromfile(const string& fileName);
    void displayrating_fromfile(const string& fileName);
    void displaypayment_fromfile(const string& fileName);

private:
    void saveDataToFile(const string& fileName, const string& data);
};

#endif /* FILEMANAGER_H */

