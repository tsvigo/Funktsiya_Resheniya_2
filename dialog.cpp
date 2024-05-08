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
std::vector<unsigned long long> list_of_neurons[201] ;//={};
long long variable_error;
QString
// std::string
    Nazvaniye_fayla_s_neyronami_i_signalom="";

bool Odin_Uchitelia;
bool Odin_Programmi;
int var ;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// 
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   std::cout << "Funktsiya_Resheniya_2"<< std::endl;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Открываем файл для решения
    /// \brief fileName
///
   if (Nazvaniye_fayla_s_neyronami_i_signalom=="")
   {
Nazvaniye_fayla_s_neyronami_i_signalom = QFileDialog::getOpenFileName(this,
              tr("Open txt"), "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/peyzaji_2/", tr("Txt Files (*.txt)"));
       // надо записать название файла с сигналоми нейронами в файл.
       // наверное не надо - мы же его содержимое не меняли 

/*----------------------------------------------------------------------------------------------------------------------*/
   }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::ifstream is( //NOTE: сигналы 1

       Nazvaniye_fayla_s_neyronami_i_signalom.toStdString().c_str()
        //NOTE: считывание в вектор нейронов и сигналов из файла (НАДО Менять для подстройки)
        );
    std::istream_iterator<unsigned long long> start(is), end;
    std::vector<unsigned long long> list_of_neurons(start, end);
    
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// считываем синапсы из файла в вектор
//    std::ifstream is2(

//    "/home/viktor/my_projects_qt_2/Funktsiya_Resheniya_2/synapses.txt"
//    //"/home/viktor/my_projects_qt_2/Funktsiya_Resheniya_2/synapses.txt"
//    );
//    std::istream_iterator<unsigned long long> start2(is2), end2;
//    std::vector<unsigned long long> list_of_synapses(start2, end2);
//########################################################################################################
    QFile file(  "/home/viktor/my_projects_qt_2/Funktsiya_Resheniya_2/synapses.txt");
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        throw std::runtime_error("Failed to open file");
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        bool ok;
        unsigned long long synaps = line.toULongLong(&ok);
        if (!ok) {
            throw std::runtime_error("Invalid synaps value in file");
        }
        list_of_synapses.push_back(synaps);
    }

    file.close();
   // return list_of_neurons;
//########################################################################################################
//   std::for_each(list_of_synapses.begin(), list_of_synapses.end(),
//              [](unsigned long long& x) { x += 1; });
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   считаем ошибку
// TODO: FIXME: тут должен быть блок вычисления 200 нейрона
//########################################################################################################
    for ( var = 100; var < 200; ++var) // This is the range of neurons
    {
        for (int neuron_index = 0, synapse_index = 0;   neuron_index < 200, synapse_index < 10100;   ++neuron_index, synapse_index = synapse_index + 100)
        
        {
            // sigpe арифметическое исключение: (СИНАПСЫ бЫЛИ 0 ДЕление на 0)
            list_of_neurons[var]=list_of_neurons[var]-  (list_of_neurons[neuron_index]/ list_of_synapses[synapse_index]); // + на -   
        } // вычитаем нейроны
    }
    
    for (int   neuron_index = 100, synapse_index = 10000; neuron_index < 200;   ++neuron_index, ++synapse_index)
    {
        list_of_neurons[200] = list_of_neurons[200] - (list_of_neurons[neuron_index] / list_of_synapses[synapse_index]); // + на -
    }
//########################################################################################################
    variable_error     =   1073741824-list_of_neurons[200] ;
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   std::cout << "variable_error = "<< variable_error<< std::endl;
   std::cout << "list_of_neurons[200] = "<< list_of_neurons[200]<< std::endl;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   показываем что определила программа
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
//########################################################################################################

QString text;
for (const auto& synapse : list_of_synapses) {
    text += QString::number(synapse) + "\n";
}

ui->textEdit->setPlainText(text);
//########################################################################################################
/// 
}

Dialog::~Dialog()
{
    delete ui;
}
//########################################################################################################//########################################################################################################//########################################################################################################
// кнопка Ошибка:
void Dialog::on_pushButton_clicked()
{
 // выбор программы обучения:
    if ( Odin_Programmi==false) // Если не распознана 1:
    {
        Odin_Uchitelia=true; ui->label_2->setText ("Odin_Programmi==false; Odin_Uchitelia=true");
        // cycle_of_distinguishing_a_one_with_vectors_GUI
        QProcess::startDetached(
          
"/home/viktor/my_projects_qt_2_build/build-cycle_of_distinguishing_a_one_with_vectors_GUI_2-Desktop_Qt_5_12_12_GCC_64bit-Debug/cycle_of_distinguishing_a_one_with_vectors_GUI_2"
                                , qApp->arguments());  
//   qApp->quit();
    }
    else // Если не распознана не 1:
    {
        Odin_Uchitelia=false;  ui->label_2->setText ("Odin_Programmi==true; Odin_Uchitelia=false");
        // bez_1
        QProcess::startDetached(

           "/home/viktor/my_projects_qt_2_build/build-bez_1_GUI-Desktop_Qt_5_12_12_GCC_64bit-Release/bez_1_GUI"
            , qApp->arguments());  
 //          qApp->quit();
    }
    //        Odin_Programmi==false;
    // если одно сочетание запускаем одну программу, если другое - другую
}

///// конец
