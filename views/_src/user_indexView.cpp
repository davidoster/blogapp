#include <QtCore>
#include <TreeFrogView>
#include "objects/user.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT user_indexView : public TActionView
{
  Q_OBJECT
public:
  user_indexView() : TActionView() { }
  QString toString();
};

QString user_indexView::toString()
{
  responsebody.reserve(1715);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n\n<h1>Listing User</h1>\n<h4>Welcome, ");
  tehex(username);
  responsebody += QStringLiteral(" - ");
  responsebody += QVariant(linkTo("Logout", QUrl("/account/logout"))).toString();
  responsebody += QStringLiteral("</h4>\n");
  responsebody += QVariant(linkTo("Create a new User", urla("create"))).toString();
  responsebody += QStringLiteral("<br />\n<br />\n<table border=\"1\" cellpadding=\"5\" style=\"border: 1px #d0d0d0 solid; border-collapse: collapse;\">\n  <tr>\n    <th>Username</th>\n    <th>Password</th>\n  </tr>\n");
  tfetch(QList<User>, userList);
  for (const auto &i : userList) {
  responsebody += QStringLiteral("  <tr>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.username());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.password());
  responsebody += QStringLiteral("</td>\n    <td>\n      ");
  responsebody += QVariant(linkTo("Show", urla("show", i.username()))).toString();
  responsebody += QStringLiteral("\n      ");
  responsebody += QVariant(linkTo("Edit", urla("save", i.username()))).toString();
  responsebody += QStringLiteral("\n      ");
  responsebody += QVariant(linkTo("Remove", urla("remove", i.username()), Tf::Post, "confirm('Are you sure?')")).toString();
  responsebody += QStringLiteral("\n    </td>\n  </tr>\n");
  };
  responsebody += QStringLiteral("</table>\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(user_indexView)

#include "user_indexView.moc"
