#include "readdata.h"
#include "constances.h"

#include <QSqlDatabase>
#include <QSqlError>

#include <QDebug>

ReadData::ReadData(QSqlDatabase &db):
    m_db(db)
{
    createConnect();
}


bool ReadData::createConnect()
{
    if(QSqlDatabase::contains("READDATA"))
        m_db = QSqlDatabase::database("READDATA");
    else
    {
        m_db = QSqlDatabase::addDatabase("QSQLITE", "READDATA");
        m_db.setDatabaseName("F:/MacaiSVN/trunk/QT/MacaiCore/AddressBook/data/data.sqlite");
    }

    if( !m_db.isOpen() )
    {
        if ( !m_db.open() )
        {
            qDebug()<< QString(" can't open database >>>>>> data.sqlite");
            qDebug() << "error code: " << m_db.lastError();
            return false;
        }
    }
    return true;
}

bool ReadData::createTable()
{
//    QStringList tableList = m_db.tables();
//    QSqlQuery query(m_db);
//    if( !tableList.contains( SQL_TABLE_FILES ) )
//    {
//        QString createTable = QString("CREATE TABLE %1 (id INTEGER PRIMARY KEY AUTOINCREMENT,"
//                                      "%2 VARCHAR(128), %3 VARCHAR(128) UNIQUE, %4 BLOB,"
//                                      "%5 VARCHAR(64), %6 VARCHAR(24), %7 VARCHAR(256) )"
//                                      )\
//                .arg(SQL_TABLE_FILES)   // ����
//                .arg(SQL_FIELD_CATEGORY)// �����
//                .arg(SQL_FIELD_NAME)    // �ļ���
//                .arg(SQL_FIELD_CONTENT) // �ļ�����
//                .arg(SQL_FIELD_SIZE)    // �ļ���С
//                .arg(SQL_FIELD_TYPE)    // �ļ�����
//                .arg(SQL_FIELD_USAGE);  // �ļ��÷�
//        if(!query.exec(createTable))
//        {
//            QMessageBox::warning(0, QObject::tr("Create table error"), QObject::tr("Error: ")+ query.lastError().text(), QMessageBox::Ok);
//            qDebug()<< "Create table error: " << query.lastError();
//            return false;
//        }
//    }

    return true;
}
