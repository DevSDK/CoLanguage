using System.Windows.Forms;
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
using System.Windows.Shapes;

namespace _3DParinterSimulation
{
    /// <summary>
    /// Interaction logic for AddWindow.xaml
    /// </summary>
    public partial class AddWindow : Window
    {

        Random random = new Random();     
        public AddWindow()
        {
            InitializeComponent();
            foreach(Model model in Datas.ModelList)
            {

                listBox.Items.Add("ID: " + model.ID + "BustTime: " + String.Format("{0:0.00}", model.BustTime) + "ms " +
                    " Watting Time: " + String.Format("{0:0.00}", model.WattingTime) + "ms " + " Name: " + model.Name);
            }
        }

        private void button_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog openFileDialog1 = new OpenFileDialog();
            openFileDialog1.Filter = "GCode Files|*";
            openFileDialog1.Title = "Select a GCode File";
            openFileDialog1.Multiselect = true;

            if (openFileDialog1.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                foreach (var file in openFileDialog1.FileNames)
                {
                    Model mod= new Model();
                    mod.Name = System.IO.Path.GetFileNameWithoutExtension(file);
                    mod.BustTime = random.NextDouble() * 10;
                    mod.WattingTime = random.NextDouble() * 10;
                    mod.ID = IDCounter++;                    
                    listBox.Items.Add("ID: " + mod.ID + "BustTime: "+ String.Format("{0:0.00}", mod.BustTime) +"ms "+
                        " Watting Time: " + String.Format("{0:0.00}", mod.WattingTime)  + "ms "+ " Name: " + mod.Name);
                    Datas.ModelList.Add(mod);
                }

              
            }
        }

        static int IDCounter = 0;
    }
}
