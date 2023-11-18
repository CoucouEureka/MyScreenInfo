#include<QFile>
#include<QScreen>
#include<QDebug>
#include <QApplication>

void writeScreensInfo(QString &screensInfo);

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
      screensInfo += "\nscreen"+ QString::number(screenNumber) + ":" + QString::number(screenNumber)
            + "\nx" + QString::number(screenNumber) + ":" +QString::number( geometry.x())
            + "\ny" + QString::number(screenNumber) + ":" +QString::number( geometry.y())
            + "\nwidth" + QString::number(screenNumber) + ":" +QString::number( geometry.width() )
            + "\nheight" + QString::number(screenNumber) + ":" +QString::number( geometry.height() );
   }

   writeScreensInfo(screensInfo);
   return 0;
}

void writeScreensInfo(QString &screensInfo)
{
   QFile file("MyScreenInfo.txt");
   if (file.exists()) { file.remove(); }
   if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
       qDebug() << "Failed to open file for writing.";
   }

   QTextStream out(&file);
   out << screensInfo;
   file.close();
}
