# Breadcrumbs
Math is awesome!

## Getting started

### Developing

#### Set Up
- Get latest ios release of [openFrameworks](http://www.openframeworks.cc/download/)
- Get latest release of [ofxEasyRetina](https://github.com/armadillu/ofxEasyRetina) and add it to the addons folder in oF
- Get latest release of [ofxRetinaTrueTypeFont](https://github.com/armadillu/ofxRetinaTrueTypeFont) and add it to the addons folder in oF
- Get latest release of [ofxGestureRecognizer](https://github.com/rjraffa/ofxGestureRecognizer) and add it to the addons folder in oF
- Clone this repository in your apps > myApps folder in oF

```
    git clone git://github.com/rjraffa/BreadcrumbsDev.git
    cd BreadcrumbsDev
```

- Open the xcodeproj file, and drag and drop the ofxEasyRetina and ofxGestureRecognizer from your local directory to the xCode project folder labeled "addons"
- Run your project!

#### Branching
- Every time you want to add a new feature or fix a bug, create a new branch based on the latest from upstream master (do *not* work off your own master branch)!

```
	git checkout master -b name-of-your-feature-branch
    git pull origin master
```

- Once you've finished your work and have added and commited your changes locally, push to *origin* repo:

```
    git push origin name-of-your-feature-branch
```

- Finally, go to GitHub and submit a pull request from your new branch.  You or a teammate can then review the request and merge it cleanly into the main master!



## Details

### Languages

- [openFrameworks](http://www.openframeworks.cc/)
- [ofxEasyRetina](https://github.com/armadillu/ofxEasyRetina)
- [ofxRetinaTrueTypeFont](https://github.com/armadillu/ofxRetinaTrueTypeFont)
- [ofxGestureRecognizer](https://github.com/rjraffa/ofxGestureRecognizer)

Thank you, [Mike Edwards](https://github.com/mikeedwards), for the awesome ReadMe format!