   M S B A M L   `   `   `  ���� F  BSettingsGUI, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null)clr-namespace:SettingsGUISettingsGUI      SettingsGUI.MainWindow   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     @d2http://schemas.microsoft.com/expression/blend/2008     Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     +localclr-namespace:SettingsGUI       � Title$  Settings GUI��$	��350��$	��525��.��� .+��� -   $��PathTxt��$��23��$��26,41,179.667,0q� �� TextWrapping$
 Wrap=�$�� ��$	��Top=��� -   $��Browse��$��	0,41,90,0q�$	��Top=�$��Right=�$��85��$��23���� $��Save file name:��$
��Left=�$��	26,10,0,0q�$	��Top=��� -   $
��Load��$��23��$��	0,41,10,0q�$	��Top=�$��Right=�$��75���� -   $��InitialEnergy��$
��Left=�$��23��$��
108,96,0,0q�$
 Wrap=�$	��662��$	��Top=�$��50���� $
��Left=�$��	26,96,0,0q�$
��Wrap=�$��Initial Energy:��$	��Top=��� $
��Left=�$��
26,126,0,0q�$
��Wrap=�$��Headers:��$	��Top=��� -   $��Headers��$��76,127,422.667,173.667q�$��20��$��20�� d� 	IsChecked$
 TrueY��� -    ��Name$ 	Tolerance��$
��Left=�$��23��$��
258,96,0,0q�$
 Wrap=�$��20��$	��Top=�$��50���� $
��Left=�$��
171,97,0,0q�$
��Wrap=�$	��Top=�$��Time Tolerance:���� -   $ 	ImageSize��$
��Left=�$��23��$��
415,97,0,0q�$
 Wrap=�$��1��$	��Top=�$��50���� $
��Left=�$��
331,96,0,0q�$
��Wrap=�$	��Top=��� $�Image size (m)���� $�:���� -   $ ImageHeight��$
��Left=�$��23��$��208,126,0,0q�$
 Wrap=�$
��0.11��$	��Top=�$��50���� $
��Left=�$��108,127,0,0q�$
��Wrap=�$	��Top=��� $�Image Height���� $
� (m)���� $�:���� -	   $ Pixels��$
��Left=�$��23��$��358,126,0,0q�$
 Wrap=�$
��1000��$	��Top=�$��50���� $
��Left=�$��276,127,0,0q�$
��Wrap=�$	��Top=�$��Pixels per side:���� $��10,154,9.667,32.667q�.���� -
   $��	FileStack���� -   $��	NumSlider�� � Value$ 0Q� �� TickFrequency$ 1Q� �� IsSnapToTickEnabled .  �� TickPlacement$
 Both=� � Maximum$ 10Q�	 � Minimum$	 1Q�$%��10,0,100                 ,9.667q�$��Bottom=��� -   $
��Save��$��23��$��0,13,9.667,0q�$	��Top=�$��Right=�$��75���� $��Right=�$��0,0,35.667,16.667q�$
��Wrap=�$��16��$��Bottom=����� 
 �� Path$
 Value� �� ElementName$ 	NumSlider��