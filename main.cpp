#include<QFile>
#include<QScreen>
#include<QDebug>
#include"../00CommonCode/commonfuncs.h"

#include <QApplication>

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);

   QList<QScreen*> screens = QGuiApplication::screens();
   int screenCnt=screens.size();
   QString screensInfo("screenCnt:"+QString::number(screenCnt));
   QScreen *screen;
   QRect geometry;
   int screenNumber;
   for (int i = 0; i < screens.size(); ++i) {
      screen = screens.at(i);
      geometry = screen->geometry();
      screenNumber = i + 1;
      screensInfo += "endlscreen"+ QString::number(screenNumber) + ":" + QString::number(screenNumber)
            + "endlx" + QString::number(screenNumber) + ":" +QString::number( geometry.x())
            + "endly" + QString::number(screenNumber) + ":" +QString::number( geometry.y())
            + "endlwidth" + QString::number(screenNumber) + ":" +QString::number( geometry.width() )
            + "endlheight" + QString::number(screenNumber) + ":" +QString::number( geometry.height() );
   }

   QString actionID=a.arguments().at(1);
   if(""==actionID){return 1;};
   QString command="\"C:\\Program Files\\Quicker\\QuickerStarter.exe\" runaction:"+ actionID +"?"+ screensInfo +"\n";
   CFuncs::commandRun(command);
   return 0;
}
