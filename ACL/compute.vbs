
Dim WshShell 
Set WshShell=WScript.CreateObject("WScript.Shell") 
WshShell.Run "cmd.exe"
WScript.Sleep 1500
WshShell.SendKeys "ssh tender-parish-accessory-elements.trycloudflare.com" 
WshShell.SendKeys "{ENTER}"
WScript.Sleep 3000 
WshShell.SendKeys "123456"
WshShell.SendKeys "{ENTER}"
WScript.Sleep 1500 
WshShell.SendKeys "cd /content"
WshShell.SendKeys "{ENTER}"
WScript.Sleep 1500 
WshShell.SendKeys "./test.sh"
WshShell.SendKeys "{ENTER}"