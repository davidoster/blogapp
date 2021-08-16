#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT account_formView : public TActionView
{
  Q_OBJECT
public:
  account_formView() : TActionView() { }
  QString toString();
};

QString account_formView::toString()
{
  responsebody.reserve(677);
  responsebody += QStringLiteral("<!DOCTYPE HTML>\n<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n</head>\n<body>\n  <h1>Login Form</h1>\n  <div style=\"color: red;\">");
  techoex(message);
  responsebody += QStringLiteral("</div>\n  ");
  responsebody += QVariant(formTag(urla("login"))).toString();
  responsebody += QStringLiteral("\n    <div>\n      User Name: <input type=\"text\" name=\"username\" value=\"\" />\n    </div>\n    <div>\n      Password: <input type=\"password\" name=\"password\" value=\"\" />\n    </div>\n    <div>\n      <input type=\"submit\" value=\"Login\" />\n    </div>\n  </form>\n</body>\n</html>");

  return responsebody;
}

T_DEFINE_VIEW(account_formView)

#include "account_formView.moc"
