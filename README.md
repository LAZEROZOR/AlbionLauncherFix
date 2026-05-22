# AlbionLauncherFix
A lightweight C++ background utility that fixes the Albion Online "invisible launcher" bug by automatically managing stuck QtWebEngine processes.

## 📝 Description

Sometimes, when launching Albion Online, the launcher's background processes start, but the user interface never renders. This is usually caused by a hang or crash in the `QtWebEngineProcess.exe` that the launcher relies on to display its web-based UI. 

This tool runs quietly in the background, detects when the Albion Launcher is running, and automatically terminates the stuck `QtWebEngineProcess.exe`, forcing the launcher to recover and display correctly.

## ⚙️ How It Works

1. The program scans the active processes to find `AlbionLauncher.exe`.
2. If the launcher is found, it searches for `QtWebEngineProcess.exe`.
3. If both are detected, it safely terminates the `QtWebEngineProcess.exe` to unfreeze the launcher's UI.

## 🔄 How to Run at PC Startup

To ensure the fix is always active without having to launch it manually, you can add a shortcut to your Windows Startup folder using its direct path:

1. Locate your compiled .exe file, right-click it, and select Create shortcut.

2. Open the File Explorer in Windows.

3. Copy and paste the following path into the address bar at the top, then press Enter:
`%APPDATA%\Microsoft\Windows\Start Menu\Programs\Startup`

The utility will now launch silently in the background every time you turn on your PC.
