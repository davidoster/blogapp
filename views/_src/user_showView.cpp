#include <QtCore>
#include <TreeFrogView>
#include "objects/user.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT user_showView : public TActionView
{
  Q_OBJECT
public:
  user_showView() : TActionView() { }
  QString toString();
};

QString user_showView::toString()
{
  responsebody.reserve(1061);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(User, user);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Showing User</h1>\n<dt>Username</dt><dd>");
  responsebody += THttpUtility::htmlEscape(user.username());
  responsebody += QStringLiteral("</dd><br />\n<dt>Password</dt><dd>");
  responsebody += THttpUtility::htmlEscape(user.password());
  responsebody += QStringLiteral("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", user.username()))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(user_showView)

#include "user_showView.moc"
