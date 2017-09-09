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
#ifndef QDOWNLOADER_H
#define QDOWNLOADER_H

#include <QObject>
#include <QUrl>
#include <QByteArray>
#include <spimpl.h>

class QDownloaderPrivate;

class QDownloader
{
    QDownloader();
public:
    static QDownloader& self()
        {
            static QDownloader dl;
            return dl;
        }
    static QByteArray download(const QUrl& url);
private:
    spimpl::impl_ptr<QDownloaderPrivate> impl;
};

#endif //QDOWNLOADER_H
