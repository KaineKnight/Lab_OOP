using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using TriangleClass;

namespace Lab6_OOP
{
    public partial class Triangles : Form
    {
        string s1, s2, s2a, s3, s3b;
        double a1, a2, angle2, a3, b3;

        private void textBox4_TextChanged(object sender, EventArgs e)
        {
            s3b = textBox4.Text;
            if (s3b != "")
            {
                s3b = s3b.Replace('.', ',');
                b3 = Convert.ToDouble(s3b);
            }
            else b3 = 0;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            t = new Right(a3, b3);
            if (a3 > 0 && b3 > 0)
            {
                textBox8.Text = Convert.ToString(t.Area());
                textBox7.Text = Convert.ToString(t.Perimeter());
            }
            else
            {
                textBox8.Text = "Нет данных";
                textBox7.Text = "Нет данных";
            }
        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {
            s3 = textBox5.Text;
            if (s3 != "")
            {
                s3 = s3.Replace('.', ',');
                a3 = Convert.ToDouble(s3);
            }
            else a3 = 0;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            t = new Isosceles(a2, angle2);
            if (a2 > 0 && angle2 > 0 && angle2 < 180)
            {
                textBox10.Text = Convert.ToString(t.Area());
                textBox9.Text = Convert.ToString(t.Perimeter());
            }
            else
            {
                textBox10.Text = "Нет данных";
                textBox9.Text = "Нет данных";
            }
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            s2a = textBox3.Text;
            if (s2a != "")
            {
                s2a = s2a.Replace('.', ',');
                angle2 = Convert.ToDouble(s2a);
            }
            else angle2 = 0;
        }
        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            s2 = textBox2.Text;
            if (s2 != "")
            {
                s2 = s2.Replace('.', ',');
                a2 = Convert.ToDouble(s2);
            }
            else a2 = 0;
        }

        Triangle t = null;
        public Triangles()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            t = new Equilateral(a1);
            if (a1 > 0)
            {
                textBox6.Text = Convert.ToString(t.Area());
                textBox11.Text = Convert.ToString(t.Perimeter());
            }
            else
            {
                textBox6.Text = "Нет данных";
                textBox11.Text = "Нет данных";
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            s1 = textBox1.Text;
            if (s1 != "")
            {
                s1 = s1.Replace('.', ',');
                a1 = Convert.ToDouble(s1);
            }
            else a1 = 0;
        }
    }
}
