#include "databaseconnection.h"
#include <QSqlQuery>
#include <QSqlError>

DataBaseConnection::DataBaseConnection(const QString &server,
                                       const QString &driver,
                                       const QString &user,
                                       const QString &password,
                                       const QString &databaseName,
                                       bool trustedConnection) {
    mDatabase = QSqlDatabase::addDatabase("QODBC");
    mDatabaseName = databaseName;
    mServer = server;
    mDriver = driver;
    mUser = user;
    mPassword = password;
    mTrustedConnection = trustedConnection;
}

bool DataBaseConnection::openDatabase(QString *error) {
    mDatabase.setDatabaseName(QString("DRIVER={%1};SERVER=%2;"
                                      "DATABASE=%3;UID=%4;PWD=%5;"
                                      "Trusted_Connection=%6;")
                              .arg(mDriver)
                              .arg(mServer)
                              .arg(mDatabaseName)
                              .arg(mUser)
                              .arg(mPassword)
                              .arg(mTrustedConnection ? "Yes" : "No"));
    if(!mDatabase.open()) {
        if(error != nullptr) {
            *error = mDatabase.lastError().text();
        }
        return false;
    }
    return true;
}
