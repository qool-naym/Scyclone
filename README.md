# <img style="float: left;" src="assets/pictures/logo.png" width="40" /> &nbsp; SCYCLONE
![rave_audition](assets/pictures/interface.png)

**Scyclone** is an audio plugin that utilizes **neural timbre transfer** technology to offer a new approach to audio production. This plugin builds upon [RAVE's](https://github.com/acids-ircam/RAVE) methodology, a realtime audio variational auto encoder, facilitating neural timbre transfer in both single and couple inference mode. <br /><br />
This enables a new artificial layering technique to be applied on the incoming signal in creating richer drum pallets, fuller atmospheres or simply transferring the timbre of the raw signal to another sound pallet. To further control the behaviour and production of the neural networks, we have internally equipped the plugin with signal processings modules allowing the user to shape, control and embellish the  source and target timbres.

## Overview
![rave_audition](assets/pictures/signal_flow_control.png)

## Installing the plugin
The plugin uses the onnxruntime libary to inference our neural networks. Unfortnuatly at the moment the library is is included as a shared library, so it is necessary to put the shared library next to the exectutable. If you are using the plugin ...
    

## Build instruction
Build with CMake
```bash
# clone the repository
git clone https://github.com/Torsion-Audio/Scyclone
cd Scyclone/

# initialize and set up submodules
git submodule update --init --recursive

# build plugin
cmake . -B cmake-build -DCMAKE_GENERATOR_PLATFORM=x64 
$ cmake --build cmake-build --config Release
```

**Note:**<br />
CMake should automatically download the prebuild onnxruntime library (version 1.12.1). **If the script fails**, use the following steps:
- Download [onnx v1.12.1](https://github.com/microsoft/onnxruntime/releases/tag/v1.12.1) (Select your required prebuild)
- Extract the file and rename to the folder ```onnxruntime-1.12.1```
- Copy to folder to ```path/to/Scyclone/modules/```
- Now you sould have the following file structes ```Scyclone/modules/onnxruntime-1.12.1/include```

## Credits

- RAVE Paper - [RAVE: A variational autoencoder for fast and high-quality neural audio synthesis](https://arxiv.org/abs/2111.05011)
- RAVE Scripts - [RAVE Github Repository](https://github.com/acids-ircam/RAVE)

## License

.....
