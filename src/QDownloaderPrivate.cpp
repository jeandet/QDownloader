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
#include <QDownloaderPrivate.h>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <iostream>
#include <QCoreApplication>

QByteArray QDownloaderPrivate::get(const QUrl& url)
{
    auto reply = p_access_mngr.get(QNetworkRequest(url));
    while(!reply->isFinished())
    {
        QCoreApplication::instance()->processEvents();
    }
    auto data = reply->readAll();
    delete reply;
    return data;
}

void QDownloaderPrivate::get_async(const QUrl& url, std::function<void(QByteArray data)> callback)
{
    auto reply = p_access_mngr.get(QNetworkRequest(url));
    QObject::connect(reply,&QNetworkReply::finished, [reply,callback](){
        auto data=reply->readAll();
        delete reply;
        callback(data);
        } );
}
