using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Interface
{
    /// <summary>
    /// Logique d'interaction pour MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void BtnCheck_Click(object sender, RoutedEventArgs e)
        {
            CBTailleTrain.IsEnabled = false;
            CBPopulation.IsEnabled = false;
            CBPolice.IsEnabled = false;
            CBPeriode.IsEnabled = false;
            CBWE.IsEnabled = false;
            CBClasse.IsEnabled = false;
            CBVacance.IsEnabled = false;
            CBGenre.IsEnabled = false;
            CBAge.IsEnabled = false;
            CBRetard.IsEnabled = false;
            CBOrigine.IsEnabled = false;
            BtnCheck.IsEnabled = false;
            BtnAccept.IsEnabled = true;
            BtnRefuse.IsEnabled = true;
        }

        private void BtnAccept_Click(object sender, RoutedEventArgs e)
        {
            CBTailleTrain.IsEnabled = true;
            CBPopulation.IsEnabled = true;
            CBPolice.IsEnabled = true;
            CBPeriode.IsEnabled = true;
            CBWE.IsEnabled = true;
            CBClasse.IsEnabled = true;
            CBVacance.IsEnabled = true;
            CBGenre.IsEnabled = true;
            CBAge.IsEnabled = true;
            CBRetard.IsEnabled = true;
            CBOrigine.IsEnabled = true;
            BtnCheck.IsEnabled = true;
            BtnAccept.IsEnabled = false;
            BtnRefuse.IsEnabled = false;
        }

        private void BtnRefuse_Click(object sender, RoutedEventArgs e)
        {
            CBTailleTrain.IsEnabled = true;
            CBPopulation.IsEnabled = true;
            CBPolice.IsEnabled = true;
            CBPeriode.IsEnabled = true;
            CBWE.IsEnabled = true;
            CBClasse.IsEnabled = true;
            CBVacance.IsEnabled = true;
            CBGenre.IsEnabled = true;
            CBAge.IsEnabled = true;
            CBRetard.IsEnabled = true;
            CBOrigine.IsEnabled = true;
            BtnCheck.IsEnabled = true;
            BtnAccept.IsEnabled = false;
            BtnRefuse.IsEnabled = false;
        }

    }
}
