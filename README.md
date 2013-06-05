# Breadcrumbs
Math is awesome!

## Getting started

### Developing

#### Set Up
- Get latest ios release of [openFrameworks](http://www.openframeworks.cc/download/)
- Get latest release of [ofxEasyRetina](https://github.com/armadillu/ofxEasyRetina) and add it to the addons folder in oF
- Get latest release of [ofxGestureRecognizer](https://github.com/rjraffa/ofxGestureRecognizer) and add it to the addons folder in oF
- Clone this repository in your apps > myApps folder in oF

```
    git clone git://github.com/EDesignLabs/wordProblematator.git
    cd wordProblematator
```

- Open the xcodeproj file, and drag and drop the ofxEasyRetina from your local directory to the xCode project folder labeled "addons"
- Run your project!

#### Branching
- Add the main EDesignLabs wordProblematator *upstream* repo as a remote on your local repo. You only ever need to do this once:

```
    git remote add upstream git://github.com/EDesignLabs/wordProblematator.git
```

- From then on, every time you want to add a new feature or fix a bug, create a new branch based on the latest from upstream (do *not* work off your own master branch)!

```
    git fetch upstream
    git checkout upstream/master -b name-of-your-feature-branch
```

- Once you've finished your work and have added and commited your changes locally, push to your own *origin* repo:

```
    git push origin name-of-your-feature-branch
```

- Finally, go to GitHub and submit a pull request from your new branch.  You or a teammate can then review the request and merge it cleanly into the main EDesignLabs master!



## Details

### Languages

- [openFrameworks](http://www.openframeworks.cc/)
- [ofxEasyRetina](https://github.com/armadillu/ofxEasyRetina)


Thank you, [Mike Edwards](https://github.com/mikeedwards), for the awesome ReadMe format!