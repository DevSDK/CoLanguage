using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Forms;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace _3DParinterSimulation
{
    /// <summary>
    /// Interaction logic for ManageWindow.xaml
    /// </summary>
    public partial class ManageWindow : Window
    {
        private Model CurrentModel;
        private Timer timer;
        private List<Model> Queue;
        private bool isDone = true;
        private double CurrentTimer = 0;


        public ManageWindow()
        {
            InitializeComponent();
            timer = new Timer();
            timer.Tick += Update;
            timer.Interval = 10;
            Queue = new List<Model>(Datas.ModelList);
            Queue.Sort(compare);
          
            foreach (Model mod in Queue)
            {
                listBox1.Items.Add("ID: " + mod.ID + " W : " + String.Format("{0:0.00}", (mod.BustTime + mod.WattingTime) / mod.BustTime) + " Name: " + mod.Name);
            }
        }
        void Update(object sender, EventArgs e)
        {

            if (isDone)
            {
                if (Queue.Count == 0)
                {
                    timer.Stop();
                    System.Windows.MessageBox.Show("Queue Is Empty");
                    return;
                }
                CurrentModel = Queue.First<Model>();
                Queue.RemoveAt(0);

                listBox1.Items.RemoveAt(0);
                CurrentTimer = CurrentModel.BustTime;
                BurstTimeTextbox_Copy.Text = "Burst Time : " + String.Format("{0:0.00}", CurrentModel.BustTime) + "ms ";
                NameTextBox.Text = "Name: " + CurrentModel.Name;

                LeftTimeTextbox.Text = "LeftTime: " + String.Format("{0:0.00}", CurrentTimer) + "ms ";
                isDone = false;
               
            }
            else if(CurrentTimer <=0)
            {
                isDone = true;
            }
                LeftTimeTextbox.Text = "LeftTime: " + String.Format("{0:0.00}", CurrentTimer);
                CurrentTimer -= 0.01;

        }
        int compare(Model x, Model y)
        {

            double Xw = (x.BustTime + x.WattingTime) / x.BustTime;
            double Yw = (y.BustTime + y.WattingTime) / y.BustTime;

            if (Xw > Yw) return 1;
            else if (Xw == Yw) return 0;
            else return -1;
        }

        private void button_Click(object sender, RoutedEventArgs e)
        {
            if (Queue.Count == 0)
            {
                System.Windows.MessageBox.Show("Queue Is Empty");
                return;
            }
            CurrentModel = Queue.First<Model>();
            Queue.RemoveAt(0);
            listBox1.Items.RemoveAt(0);
            BurstTimeTextbox_Copy.Text = "Burst Time : "+ String.Format("{0:0.00}", CurrentModel.BustTime)+"ms ";
            CurrentTimer = CurrentModel.BustTime;
            NameTextBox.Text ="Name: "+ CurrentModel.Name;
            LeftTimeTextbox.Text = "LeftTime: " + String.Format("{0:0.00}", CurrentTimer)  +"ms "; 
            isDone = false;
            timer.Start();
        }
    }
}
