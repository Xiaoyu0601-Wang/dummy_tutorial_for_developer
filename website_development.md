### Node.js Installation
```sh
sudo apt update && sudo apt install -y nodejs npm
sudo apt install cmdtest
```

### Website Template
https://github.com/issaafalkattan/React-Landing-Page-Template

## Instruction
### Install Dependencies

Depending on which package manager the project uses:
If you see a package-lock.json → use npm:
```sh
npm install
```

If you want to serve a built static version
First, build the project:
```sh
npm run build
```

Now you can open it in two ways:
Easiest: install serve and run a local server:
```sh
npm install -g serve
serve -s build
```

Start website test:
```sh
npm start
```