/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtWebEngine module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef SHARED_GLOBALS_H
#define SHARED_GLOBALS_H

#include "base/files/file_path.h"
#include "third_party/WebKit/public/platform/WebScreenInfo.h"

#include <QString>

#ifdef QT_WEBENGINE_LOGGING
#define QT_NOT_YET_IMPLEMENTED fprintf(stderr, "function %s not implemented! - %s:%d\n", __func__, __FILE__, __LINE__);
#define QT_NOT_USED fprintf(stderr, "# function %s should not be used! - %s:%d\n", __func__, __FILE__, __LINE__); Q_UNREACHABLE();
#else
#define QT_NOT_YET_IMPLEMENTED qt_noop();
#define QT_NOT_USED Q_UNREACHABLE(); // This will assert in debug.
#endif

namespace content {
class WebContentsImpl;
class WebContentsViewPort;
class WebContentsViewDelegate;
class RenderViewHostDelegateView;
} // namespace content

class QWindow;

void GetScreenInfoFromNativeWindow(QWindow* window, WebKit::WebScreenInfo* results);


inline base::FilePath::StringType qStringToStringType(const QString &str)
{
#if defined(OS_POSIX)
    return str.toStdString();
#elif defined(OS_WIN)
    return str.toStdWString();
#endif
}

#endif
