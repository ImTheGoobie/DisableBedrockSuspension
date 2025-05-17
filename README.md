# DisableBedrockSuspension

This small C program will prevent the UWP App Suspension that Minecraft: Bedrock Edition suffers from.
Just simply add it to your startup folder and profit!

You can download the executable from [here](https://github.com/ImTheGoobie/DisableBedrockSuspension/releases/tag/release) or build from source using gcc:

```
gcc -Os -s -mwindows -nostdlib main.c -lKernel32 -lOle32 -lShell32 -o DisableBedrockSuspension.exe
```
