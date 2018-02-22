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

using Ookii.Dialogs.Wpf;
using System.IO;

namespace SettingsGUI
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        List<DetectorInputs> detectors = new List<DetectorInputs>();

        public MainWindow()
        {
            InitializeComponent();
        }

        private void BrowseClick(object sender, RoutedEventArgs e)
        {
            VistaOpenFileDialog dialog = new VistaOpenFileDialog();
            dialog.DefaultExt = ".txt";
            dialog.InitialDirectory = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments);
            dialog.Title = "Select the save file path..";

            if (dialog.ShowDialog() == true)
            {
                PathTxt.Text = dialog.FileName;
                LoadFile();
            }
        }

        private void LoadClick(object sender, RoutedEventArgs e)
        {
            LoadFile();
        }










        private void LoadFile()
        {
            FileStack.Children.Clear();
            detectors.Clear();

            string path = PathTxt.Text;
            int detectorCounts = 0;

            string[] lines = File.ReadAllLines(path);
            foreach(string line in lines)
            {
                string[] splits = line.Split(' ');
                if (splits[0] == "DetectorCount")
                {
                    detectorCounts = int.Parse(splits[1]);
                    for (int i = 0; i < detectorCounts; i++) detectors.Add(new DetectorInputs());
                }
                else if (splits[0] == "InitialEnergy")
                    InitialEnergy.Text = splits[1];
                else if (splits[0] == "IsSimulationData")
                    Headers.IsChecked = (splits[1] == "1") ? true : false;
                else if (splits[0] == "Tolerance")
                    Tolerance.Text = splits[1];
                else if (splits[0] == "ImageSize")
                    ImageSize.Text = splits[1];
                else if (splits[0] == "ImageHeight")
                    ImageHeight.Text = splits[1];
                else if (splits[0] == "PixelCount")
                    Pixels.Text = splits[1];
                else
                {
                    for (int i = 0; i < detectorCounts; i++)
                    {
                        if (splits[0] == "Detector" + i + "x")
                            detectors[i].XPos.Text = splits[1];
                        else if (splits[0] == "Detector" + i + "z")
                            detectors[i].ZPos.Text = splits[1];
                        else if (splits[0] == "Detector" + i + "type")
                            detectors[i].IsScatter.IsChecked = (splits[1] == "1") ? true : false;
                        else if (splits[0] == "Detectorfp" + i)
                            detectors[i].FilePathTxt.Text = splits[1];
                    }
                }
            }



            for (int i = 0; i < detectorCounts; i++)
            {
                FileStack.Children.Add(detectors[i]);
            }
            NumSlider.Value = detectorCounts;
        }

        private void Slider_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            int count = detectors.Count;
            if (NumSlider.Value > count)
            {
                //Add new
                FileStack.Children.Add(new DetectorInputs());
            }
            else
            {

                for (int i = 0; i < count - NumSlider.Value; i++)
                {
                    detectors.RemoveAt(count - i);
                    FileStack.Children.RemoveAt(count - i);
                }
            }
        }

        private void SaveClicked(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("NOT IMPL");
        }
    }
}
