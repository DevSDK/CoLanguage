using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace _3DParinterSimulation
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private List<Model> ModelList = new List<Model>();
        
        public MainWindow()
        {
            Datas.ModelList = ModelList;
         
            InitializeComponent();
        }

        private void button_Click(object sender, RoutedEventArgs e)
        {
            AddWindow addWindow= new AddWindow();
            addWindow.Show();
        }

        private void button1_Click(object sender, RoutedEventArgs e)
        {
            ManageWindow manageWindow = new ManageWindow();
            manageWindow.Show();
        }
    }
}
