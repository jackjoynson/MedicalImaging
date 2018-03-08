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

namespace CCSettingsGUI
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
            try
            {
                FileStack.Children.Clear();
                detectors.Clear();

                string path = PathTxt.Text;
                int detectorCounts = 0;

                string[] lines = File.ReadAllLines(path);
                foreach (string line in lines)
                {
                    string[] splits = line.Split(' ');
                    if (splits[0] == "DetectorCount")
                    {
                        detectorCounts = int.Parse(splits[1]);
                        for (int i = 0; i < detectorCounts; i++) detectors.Add(new DetectorInputs());
                    }
                    else if (splits[0] == "Headers")
                        Headers.IsChecked = (splits[1] == "1") ? true : false;
                    else if (splits[0] == "Tolerance")
                        Tolerance.Text = splits[1];
                    else if (splits[0] == "Output")
                        Output.Text = splits[1];
                    else if (splits[0] == "OverRide")
                        Override.IsChecked = (splits[1] == "1") ? true : false;
                    else if (splits[0] == "EnergyLimits")
                        EnergyLimits.IsChecked = (splits[1] == "1") ? true : false;
                    else if (splits[0] == "EnergyUpperLimit")
                        UpperLim.Text = splits[1];
                    else if (splits[0] == "EnergyLowerLimit")
                        LowerLim.Text = splits[1];
                    else if (splits[0] == "MultiMode")
                        MultiMode.IsChecked = (splits[1] == "1") ? true : false;
                    else
                    {
                        for (int i = 0; i < detectorCounts; i++)
                        {
                            if (splits[0] == "Detector" + i + "calM")
                                detectors[i].CalGrad.Text = splits[1];
                            else if (splits[0] == "Detector" + i + "calK")
                                detectors[i].CalConst.Text = splits[1];
                            else if (splits[0] == "Detector" + i + "offset")
                                detectors[i].TimeOffset.Text = splits[1];
                            else if (splits[0] == "Detector" + i + "fp")
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
            catch (Exception err)
            {
                MessageBox.Show("Error reading file: " + err.ToString());
            }
        }

        private void Slider_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            int count = detectors.Count;
            if (NumSlider.Value > count)
            {
                DetectorInputs DI = new DetectorInputs();

                FileStack.Children.Add(DI);
                detectors.Add(DI);
            }
            else if(NumSlider.Value < count)
            {

                for (int i = 1; i < count - NumSlider.Value; i++)
                {
                    detectors.RemoveAt(count - i);
                    FileStack.Children.RemoveAt(count - i);
                }
            }
        }

        private void SaveClicked(object sender, RoutedEventArgs e)
        {
            StringBuilder sb = new StringBuilder();
            sb.Append("DetectorCount ").Append(detectors.Count).AppendLine();

            sb.Append("Headers ");
            if(Headers.IsChecked == true) sb.Append("1");
            else sb.Append("0");
            sb.AppendLine();

            sb.Append("Tolerance ").Append(Tolerance.Text).AppendLine();
            sb.Append("Output ").Append(Output.Text).AppendLine();

            sb.Append("OverRide ");
            if (Override.IsChecked == true) sb.Append("1");
            else sb.Append("0");
            sb.AppendLine();

            sb.Append("EnergyLimits ");
            if (EnergyLimits.IsChecked == true) sb.Append("1");
            else sb.Append("0");
            sb.AppendLine();

            sb.Append("EnergyUpperLimit ").Append(UpperLim.Text).AppendLine();
            sb.Append("EnergyLowerLimit ").Append(LowerLim.Text).AppendLine();

            sb.Append("MultiMode ");
            if (MultiMode.IsChecked == true) sb.Append("1");
            else sb.Append("0");
            sb.AppendLine();


            for (int i = 0; i < detectors.Count; i++)
            {
                sb.Append("Detector").Append(i).Append("fp ")
                    .Append(detectors[i].FilePathTxt.Text).AppendLine();

                sb.Append("Detector").Append(i).Append("calM ")
                    .Append(detectors[i].CalGrad.Text).AppendLine();

                sb.Append("Detector").Append(i).Append("calC ")
                    .Append(detectors[i].CalConst.Text).AppendLine();

                sb.Append("Detector").Append(i).Append("offset ")
                    .Append(detectors[i].TimeOffset.Text).AppendLine();           

            }

            File.WriteAllText(PathTxt.Text.Trim(), sb.ToString());
        }
    }
}
