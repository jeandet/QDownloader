/*------------------------------------------------------------------------------
--  This file is a part of the QDownloader library
--  Copyright (C) 2017, Plasma Physics Laboratory - CNRS
--
--  This program is free software; you can redistribute it and/or modify
--  it under the terms of the GNU General Public License as published by
--  the Free Software Foundation; either version 2 of the License, or
--  (at your option) any later version.
--
--  This program is distributed in the hope that it will be useful,
--  but WITHOUT ANY WARRANTY; without even the implied warranty of
--  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
--  GNU General Public License for more details.
--
--  You should have received a copy of the GNU General Public License
--  along with this program; if not, write to the Free Software
--  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
-------------------------------------------------------------------------------*/
/*--                  Author : Alexis Jeandet
--                     Mail : alexis.jeandet@member.fsf.org
----------------------------------------------------------------------------*/
#include <QtTest/QtTest>
#include <QDownloader.h>
#include <QString>
#include <iostream>

class SimpleDownload: public QObject
{
    Q_OBJECT
private slots:
    void initTestCase();
    void download();
};

void SimpleDownload::initTestCase()
{
}

void SimpleDownload::download()
{
    auto left = QString("Lorem ipsum dolor sit amet");
    auto right = QString("no sea takimata sanctus est Lorem ipsum dolor sit amet.");
    auto txt = QString(QDownloader::download(QUrl{"http://www.loremipsum.de/downloads/original.txt"}));
    QCOMPARE(txt.left(left.size()), left);
    QCOMPARE(txt.right(right.size()), right);
}

QTEST_MAIN(SimpleDownload)
#include "simple_download.moc"
