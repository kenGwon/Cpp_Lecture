using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        DateTime now = DateTime.Now;

        public DateTime GetStartDateTime()
        {
            return now;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show(GetStartDateTime().ToString());
        }

        private void button2_Click(object sender, EventArgs e)
        {
            MessageBox.Show("어서와 C# 프로그램이야!!");
        }
    }
}
