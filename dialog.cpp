#include "dialog.h"
#include "ui_dialog.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Dialog::Dialog
/// \param parent
using namespace std;
#include <iostream>
#include <fstream>
#include <QFileDialog>
#include <QTextStream>
#include <QProcess>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief list_of_synapses
/// переменные:
std::vector<unsigned long long> list_of_synapses ;
std::vector<unsigned long long
            //  int
            > list_of_neurons[201] ;//={};
long long variable_error;
QString
// std::string
    Nazvaniye_fayla_s_neyronami_i_signalom="";
  //  "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/0-2/neurons_and_signal.txt";
bool Odin_Uchitelia;
bool Odin_Programmi;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// 
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    QFile file("/home/viktor/my_projects_qt_2/Funktsiya_Resheniya_2/название файла с нейронами и сигналами.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    
    QTextStream out(&file);
    out << Nazvaniye_fayla_s_neyronami_i_signalom ;// "\n";
    file.close(); 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   std::cout << "Funktsiya_Resheniya_2"<< std::endl;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief fileName
///
   if (Nazvaniye_fayla_s_neyronami_i_signalom=="")
   {
Nazvaniye_fayla_s_neyronami_i_signalom = QFileDialog::getOpenFileName(this,
                                           tr("Open txt"), "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly", tr("Txt Files (*.txt)"));
       // надо записать название файла с сигналоми нейронами в файл
/*----------------------------------------------------------------------------------------------------------------------*/
QFile file("/home/viktor/my_projects_qt_2/Funktsiya_Resheniya_2/название файла с нейронами и сигналами.txt");
if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    return;

QTextStream out(&file);
out << Nazvaniye_fayla_s_neyronami_i_signalom;
file.close();
/*----------------------------------------------------------------------------------------------------------------------*/
   }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::ifstream is( //NOTE: сигналы 1
        // "/home/viktor/my_projects_qt_2/cycle_of_distinguishing_a_one_with_vectors/neurons_and_signal.txt" // 1.bmp
        //   "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/1-1/neyroni_i_signal.txt" // 1-1.bmp
        
        //  "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/0/neyroni_i_signal.txt"
        // 1:
        //  "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/1/neurons_and_signal-2.txt" //NOTE: BMP
        // 2:
        //    "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/1-1(2)/neyroni_i_signal.txt"
        // 3:
      //  "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/0-2/neurons_and_signal.txt"
       Nazvaniye_fayla_s_neyronami_i_signalom.toStdString().c_str()
        //NOTE: считывание в вектор нейронов и сигналов из файла (НАДО Менять для подстройки)
        );
    std::istream_iterator<unsigned long long> start(is), end;
    std::vector<unsigned long long> list_of_neurons(start, end);
    
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::ifstream is2("/home/viktor/my_projects_qt_2/cycle_of_distinguishing_a_one_with_vectors/synapses.txt-4");
    std::istream_iterator<unsigned long long> start2(is2), end2;
    std::vector<unsigned long long> list_of_synapses(start2, end2);
    // f:
    // std::jmp_buf f;
    // std::longjmp(f, true); // Go to error handler
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   
    variable_error     =   1073741824-list_of_neurons[200] ;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   
    if 
        ( variable_error <=0)

    {
        ui->label->setText(Nazvaniye_fayla_s_neyronami_i_signalom+"\n"+"Программа считает что это 1.");
        Odin_Programmi=true;
    }
                           else {
        ui->label->setText(Nazvaniye_fayla_s_neyronami_i_signalom+"\n"+"Программа считает что это не 1.");
          Odin_Programmi=false;
    }
/// 
/// Должна быть переменная для названия файла с нейронами и сигналом. nazvaniya fayla s neyronami i signalom
/// Булева переменная в которую учитель записывает один это правильно или нет.
/// Видимо и переменная что решила программа должна быть. Если две переменных совпадают ничего не делаем. Если не совпадают то возможны 2 случая:
///   1) bool Odin_Uchitelia==true;
//       bool Odin_Programmi==false;
///
    ///   2) bool Odin_Uchitelia==false;
    //       bool Odin_Programmi==true;
/// 
/// 
/// 
/// 
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    if ( Odin_Programmi==false)
    {
        Odin_Uchitelia=true; ui->label_2->setText ("Odin_Programmi==false; Odin_Uchitelia=true");
        // cycle_of_distinguishing_a_one_with_vectors_GUI
        QProcess::startDetached(
          //  "/home/viktor/my_projects_qt_2/build-bez_1-Desktop_Qt_5_12_12_GCC_64bit-Debug/bez_1"
"/home/viktor/my_projects_qt_2/build-cycle_of_distinguishing_a_one_with_vectors_GUI-Desktop_Qt_5_12_12_GCC_64bit-Debug/cycle_of_distinguishing_a_one_with_vectors_GUI"
                                , qApp->arguments());  
//   qApp->quit();
    }
    else
    {
        Odin_Uchitelia=false;  ui->label_2->setText ("Odin_Programmi==true; Odin_Uchitelia=false");
        // bez_1
        QProcess::startDetached(
            //  "/home/viktor/my_projects_qt_2/build-bez_1-Desktop_Qt_5_12_12_GCC_64bit-Debug/bez_1"
//"/home/viktor/my_projects_qt_2/build-bez_1-Desktop_Qt_5_12_12_GCC_64bit-Debug/bez_1"
            "/home/viktor/my_projects_qt_2/build-bez_1_GUI-Desktop_Qt_5_12_12_GCC_64bit-Debug/bez_1_GUI"
            , qApp->arguments());  
 //          qApp->quit();
    }
    //        Odin_Programmi==false;
    // если одно сочетание запускаем одну программу, если другое - другую
}

