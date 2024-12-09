
![[Screenshot 2024-11-25 at 11.32.15 PM.png]]

* This is how th basic set-up flow looks like
* the server first runs some db query and key the render shell prepared before any requested
* once a request to the server is made it sends these already generated html/css to the client.
* this significantly reduces the load on the client.
* once the bundle is downloaded the hydration process will start and react will parse thropugh all of the code base and starts assigning the event listerners to each components.
* later on from here additional information required by the client are requsted through db call and then the page re-renders

* the FP(first Print) or partial data is already present before downloading the js bundle
* the page becomes interactive only when the hydration is completed.

![[Screenshot 2024-11-25 at 11.40.30 PM.png]]

### What is the problem with this approach?

let us say we have 200 components each of 1MB size and 150 of them are just for data display and the remaining 50 are for interactivity. then there is no point of downloading the javascript for the text based components. this will just increase the bundle size.
# React Server Components

* Here is where the usage of server components will come into picture.
we can mark those 150 components as server and the remainig 50 as client this will reduce the bundle size also.
* these 150 component's are not shipped to the front-end but they are rendered on the backend and are streamed on the frontend.
* this reduces the bundle size increasing the website speed, faster hydration, speed interaction.


SSR means both on server and on client.
RSC means only on the server.


