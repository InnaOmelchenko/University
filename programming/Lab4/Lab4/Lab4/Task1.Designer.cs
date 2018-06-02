namespace Lab4
{
    partial class Task1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.helpProvider1 = new System.Windows.Forms.HelpProvider();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // textBox1
            // 
            this.helpProvider1.SetHelpString(this.textBox1, "For input integer A");
            this.textBox1.Location = new System.Drawing.Point(70, 33);
            this.textBox1.Name = "textBox1";
            this.helpProvider1.SetShowHelp(this.textBox1, true);
            this.textBox1.Size = new System.Drawing.Size(100, 22);
            this.textBox1.TabIndex = 0;
            // 
            // textBox2
            // 
            this.helpProvider1.SetHelpString(this.textBox2, "For input integer B");
            this.textBox2.Location = new System.Drawing.Point(70, 78);
            this.textBox2.Name = "textBox2";
            this.helpProvider1.SetShowHelp(this.textBox2, true);
            this.textBox2.Size = new System.Drawing.Size(100, 22);
            this.textBox2.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(29, 33);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(17, 17);
            this.label1.TabIndex = 2;
            this.label1.Text = "A";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(29, 78);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(17, 17);
            this.label2.TabIndex = 3;
            this.label2.Text = "B";
            // 
            // button1
            // 
            this.helpProvider1.SetHelpString(this.button1, "Press this button to start work");
            this.button1.Location = new System.Drawing.Point(32, 132);
            this.button1.Name = "button1";
            this.helpProvider1.SetShowHelp(this.button1, true);
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 4;
            this.button1.Text = "Start work";
            this.button1.UseVisualStyleBackColor = true;
            // 
            // button2
            // 
            this.helpProvider1.SetHelpString(this.button2, "Press this button to sum A and B");
            this.button2.Location = new System.Drawing.Point(157, 132);
            this.button2.Name = "button2";
            this.helpProvider1.SetShowHelp(this.button2, true);
            this.button2.Size = new System.Drawing.Size(75, 23);
            this.button2.TabIndex = 5;
            this.button2.Text = "Sum";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.UseWaitCursor = true;
            // 
            // Task1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(282, 253);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.textBox1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.HelpButton = true;
            this.helpProvider1.SetHelpString(this, "");
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Task1";
            this.helpProvider1.SetShowHelp(this, true);
            this.Text = "Task1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.HelpProvider helpProvider1;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
    }
}