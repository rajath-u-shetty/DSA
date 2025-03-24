#### How does the basic architecture of react works?

![[Screenshot 2024-11-25 at 10.22.42 PM.png]]

When a user makes an HTTP request to access a React-based website, the server responds with a **JavaScript (JS) bundle** that contains the code needed to render the application on the client side. Here's how the basic architecture and workflow operate:

### Workflow of React Rendering

1. **Initial HTTP Request**  
    The browser sends a request to the server. In response, the server sends back a JS bundle that includes the React application code.
    
2. **Rendering the "Shell"**  
    Once the JS bundle is downloaded, the browser starts rendering the **shell** of the application. This includes static components like the header, footer, and the basic layout of the webpage. At this stage:
    
    - The page structure (HTML elements) becomes visible.
    - States and props are initialized as per the React code.
    - However, much of the content, such as dynamic data fetched from APIs or databases, is not yet available.
3. **Execution of `useEffect` and Data Fetching**  
    During the shell rendering process, React executes all the `useEffect` hooks defined in the components. These hooks are typically used for:
    
    - Fetching data from APIs or databases.
    - Setting up event listeners.
    - Performing side effects.  
        Once the required data is fetched, React updates the state or props accordingly.
4. **Re-rendering with Fetched Data**  
    After the data is successfully retrieved, React re-renders the necessary components to display the full content. This ensures the webpage is fully interactive and ready for the user.
    

---

### Pros of React

React provides a fantastic **developer experience** due to its modular approach, reusable components, and tools like the React DevTools. Additionally, its declarative style makes it easier to reason about the UI state and behavior.

---

### Cons of React's Architecture

The challenges of a React-based client-side rendering (CSR) architecture are depicted by the vertical lines in the provided image. Here's a breakdown:

1. **Initial Blank Screen (JS Download Time)**

    - Before rendering the shell, the browser needs to download and parse the entire JS bundle.
    - The larger the JS bundle, the longer this delay becomes, leading to a **blank screen** for the user during the initial loading phase.
2. **Shell Rendering Without Functionality**
    
    - Once the JS is processed, the **First Paint (FP)** of the webpage occurs.
    - At this point, the user can see a skeleton or layout of the website with basic interactive elements like buttons or input fields.
    - However, these elements lack functionality since the data-fetching process is still ongoing.
3. **Delayed Content Visibility**
    
    - Dynamic content becomes visible only after database queries or API calls are completed and the state updates. This can create a poor user experience if fetching data takes too long.
4. **Suboptimal User Experience and SEO**
    
    - Client-side rendering can negatively impact user experience and **Search Engine Optimization (SEO)**.
    - Search engines may struggle to index dynamically generated content, and users may leave due to the initial delays.


### Imp key    points

- **Improving React's Performance**
    
    - Use **Code Splitting** with tools like `React.lazy` and `React Suspense` to load components only when needed.
    - Leverage **Server-Side Rendering (SSR)** with frameworks like Next.js to improve SEO and reduce the initial blank screen time. SSR sends pre-rendered HTML to the client, which reduces the dependence on the JS bundle for basic content.
    - Consider **Static Site Generation (SSG)** for pages that don't change frequently.
    
- **Hydration Process**
    - React "hydrates" the shell rendered on the browser by attaching event listeners and making it interactive. This is a crucial step to convert a static page into a dynamic React application.
    
- **Strategies for Better SEO**
    - Use meta tags to provide meaningful titles, descriptions, and keywords.
    - Employ **structured data** (e.g., JSON-LD) to help search engines understand your content.
    
- **React's Virtual DOM**
    - React's Virtual DOM is one of its core strengths. Changes are applied to the virtual DOM first, and only the differences are updated on the actual DOM, resulting in better performance.
    
- **Progressive Web Applications (PWA)**
    - React can be used to build **Progressive Web Apps** to provide a more native app-like experience, including offline support and faster load times.