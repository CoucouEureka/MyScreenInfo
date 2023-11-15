#include<QProcess>
#include<QScreen>
#include<QDebug>

#include <QApplication>

QString commandRun(QString &);

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
   commandRun(command);
   return 0;
}

QString commandRun(QString &command)
{
   QByteArray byteArray = command.toLocal8Bit();
   QProcess process;

   process.start("cmd.exe");
   process.waitForStarted();
   process.write(byteArray);
   process.closeWriteChannel();
   process.waitForFinished();

   return  QString::fromLocal8Bit(process.readAll());
}
