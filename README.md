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

Sandbox:
* ....Not going to do it.

REF:
http://www.html5rocks.com/en/tutorials/internals/howbrowserswork/