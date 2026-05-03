# YOLO Environment
The following installing steps takes python3.8.20,cuda_vision12.4,conda as an example.
## Install python environment 
Installing the needed python version:
```sh
conda create -n my_env python=3.8.20
```

## Install torch environment
The torch environment is dependent on the vision of cuda.Refer to the torch official website(https://pytorch.org/):
```sh
conda install pytorch==2.4.1 torchvision==0.19.1 torchaudio==2.4.1 pytorch-cuda=12.4 -c pytorch -c nvidia
```

## Ultrtalytics install
Ultrtalytics can be installed directly from below by conda or pip.If needed, you can download original code from the official website(https://github.com/ultralytics/ultralytics).
```sh
conda install ultrtalytics
```

## ONNX install
The vision of ONNX need to adapt the vision of yolo and torch.For the example above:
```sh
conda install onnx==1.16.2 onnxruntime==1.19.2
```

## Optional package
polar
matplotlib