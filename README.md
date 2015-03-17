How browser works?

I had poking around webkit core source code a long long time ago, 
now it is the time to build a toy one, to see if I am really get it.


TODO Draft:

* parsing HTML to a DOM tree. I don't think I really need a shadow tree right now.
* parsing css, to generate style rules
* combine DOM and style rules to get a render tree
* layout engine consume the render tree
* the paint device take out the produce graphic context
* not all w3c spec will be supported, by box model and basic tag will be.

Javascipr part:

* javascript engine first use V8 or other open souce js engine
* then maybe replace it with some crapy rolled your own version?
* events

Sandbox/multiprocess/webkit2:
* ....Not going to do it.

REF:
http://www.html5rocks.com/en/tutorials/internals/howbrowserswork/

C++ implementation of Matt Brubeck's blog "let's build a broweser engine"
[blog]: http://limpet.net/mbrubeck/2014/08/08/toy-layout-engine-1.html
[robinson]: https://github.com/mbrubeck/robinson


Status
------
- [ ] Part 0: confront google style and use plain C++ not QOject
- [x] Part 1: Getting started
- [x] Part 2: HTML
- [x] Part 3: CSS
- [x] Part 4: Style
- [ ] Part 5: Boxes
- [ ] Part 6: Block layout 
- [ ] Part 7: Painting 101
