VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3015
   ClientLeft      =   120
   ClientTop       =   465
   ClientWidth     =   5970
   LinkTopic       =   "Form1"
   ScaleHeight     =   3015
   ScaleWidth      =   5970
   StartUpPosition =   3  '����ȱʡ
   Begin VB.TextBox Text2 
      Height          =   1575
      Left            =   360
      Locked          =   -1  'True
      MultiLine       =   -1  'True
      ScrollBars      =   2  'Vertical
      TabIndex        =   3
      Text            =   "change.frx":0000
      Top             =   1320
      Width           =   3615
   End
   Begin VB.TextBox Text1 
      Height          =   375
      Left            =   2280
      TabIndex        =   1
      Text            =   "100"
      Top             =   480
      Width           =   1695
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Compute!"
      Height          =   1455
      Left            =   4440
      TabIndex        =   0
      Top             =   1440
      Width           =   1335
   End
   Begin VB.Label Label1 
      Caption         =   "������Ҫ�ҵ���Ǯ��"
      Height          =   495
      Left            =   360
      TabIndex        =   2
      Top             =   480
      Width           =   1695
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
    Dim total%
    total = Val(Text1.Text)
    cnt = 0
    msg = "5 Ԫ" & vbTab & "10 Ԫ" & vbTab & "20 Ԫ" & vbCrLf
    For i = 0 To total / 5
        For j = 0 To (total - i * 5) / 10
            For k = 0 To (total - i * 5 - j * 10) / 20
                If 5 * i + 10 * j + 20 * k = total Then
                    cnt = cnt + 1
                    msg = msg & i & vbTab & j & vbTab & k & vbCrLf
                End If
            Next k
        Next j
    Next i
    msg = "����" & cnt & "�֣��������£�" & vbCrLf & msg
    Text2.Text = msg
End Sub

Private Sub Form_Load()
    Form1.Caption = "Change"
    Text2.Text = "��������ֵ������Ҳఴť��"
End Sub

