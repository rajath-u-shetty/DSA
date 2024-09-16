## problem

![[Screenshot 2024-09-15 at 8.15.41 PM.png]]
### Throughput Bottleneck in Databases

- Traditional databases have limitations when handling a large number of operations per second (OPS).
- This means that performing too many insert operations in a short amount of time can overwhelm the database.
- For example, if the number of insert operations exceeds the database’s capacity, the server might slow down or crash.


### Example: Ride-Hailing Apps (Ola/Uber)

![[Screenshot 2024-09-15 at 8.30.38 PM.png]]

- When a ride is booked in apps like Ola and Uber, multiple types of data are generated, such as:
    - **Driver position (longitude/latitude)**
    - **Driver speed**
    - **Distance from the customer**
    - **Destination coordinates**
- The app must continuously update the user about the driver’s position in real-time, usually sending updates every second.
- For example:
    1. Initially, the driver’s position is fetched.
    2. Next, the customer’s position is fetched.
    3. Once the driver picks up the customer, the app tracks the driver’s movement toward the destination.
- **Operations per Second (OPS)**:
    - If there are 1,000 drivers, and each update requires 3 operations (fare calculation, analytics, customer update), the system will need to handle 3,000 write operations per second.
    - This volume can crash the database if it is not designed to handle high throughput.


---

# Kafka

*   Kafka is a distributed streaming platform that can handle a high number of events (records) per second.
- Kafka has **high throughput**, meaning it can process a vast amount of data without becoming overloaded.

## why not use kafka instead of a database?

![[Screenshot 2024-09-15 at 8.31.08 PM.png]]

* While Kafka can handle large amounts of data quickly, it is not a replacement for a traditional database because:

- **Storage Limitations**: Kafka can store data for only a limited time (usually configured to hold data for a few days or weeks).
- **Querying**: You cannot query or retrieve historical data as you would with a database.
- **Role**: Kafka is used for **data streaming**, while databases are used for **data storage and querying**.

### Kafka vs. Database

| Feature        | Kafka                   | Database                 |
| -------------- | ----------------------- | ------------------------ |
| **Throughput** | High                    | Low                      |
| **Storage**    | Low (limited retention) | High (long-term storage) |
| **Querying**   | No (stream-based)       | Yes (queryable records)  |

***

### Kafka Usage in the Ride-Hailing Example

![[Screenshot 2024-09-15 at 8.47.59 PM.png]]

1. - **Producers (e.g., Ola/Uber)**:
    - When millions of events (driver location, customer updates) are generated every second, the system cannot write this data directly to the database without crashing.
- **Kafka Layer**:
    - Kafka is placed between the app and the database.
    - Kafka **collects and processes** the high-velocity data streams in real-time.
    - It **temporarily stores** the data and performs necessary calculations (e.g., fare estimation, distance tracking).
- **Bulk Data Insertion**:
    - Once Kafka processes a batch of data, it performs **bulk insertion** into the database, reducing the load on the database.
    - For instance, Kafka can handle and insert a million records in a single transaction, ensuring efficient and safe storage in the database.


# Kafka Architecture

![[Screenshot 2024-09-15 at 9.27.54 PM.png]]

- ### Zomato Example

- In this example, **Zomato** acts as the producer, generating multiple types of data (e.g., rider updates, restaurant updates).
    
- This data flows into Kafka, where it is categorized into different **topics**. Each **topic** is a logical grouping of related data, ensuring that different types of data are handled separately.
    
    Example:
    
    - **Topic 1**: Rider updates (location, status, etc.)
    - **Topic 2**: Restaurant updates (menu changes, availability, etc.)
- **Partitioning**:
    
    - Kafka can partition data within each topic. For instance, the data within the "Rider" topic can be further split by **geographical region** or **city**.
    - Data is stored in a partition based on a specific criterion, such as rider location or restaurant status, which enhances the ability to scale Kafka horizontally.
- **Consumer Handling**:
    
    - Consumers read data from these topics. Kafka ensures that the data meant for each consumer is routed correctly based on the **type of update**.
    - If a device is identified as a rider’s phone, the data will be routed to the **Rider topic**. The same applies for restaurants and the **Restaurant topic**.
- **Database Partitioning**:
    
    - As topics grow larger, **partitioning** can be applied to further organize the data into smaller, more manageable units.
    - **Database partitioning** is often used to store incoming Kafka data into **separate databases** based on certain conditions (e.g., by city or restaurant).
    - This partitioning of databases ensures faster querying and retrieval of relevant data later on.
- **Bulk Insertion**:
    
    - Once Kafka has accumulated a significant amount of data, it performs **bulk insertions** into the relevant databases (one for rider data, another for restaurant data). This approach optimizes database performance by reducing the number of individual write operations.
  
# kafka architecture eg

![[Screenshot 2024-09-15 at 10.50.57 PM.png]]

- ### Single Producer with Partitioned Data

- In this case, we have a **single producer** (for example, data from a ride-hailing app or delivery service) that generates data.
    
- **Kafka Topic with Partitions**:
    - The data is sent to a **Kafka topic**, but the topic is **partitioned** (for instance, based on **geographical directions**—North, South, East, West).
    - Data from the North region would be routed to the first partition, data from the South to the second, and so on.
- **Single Consumer**:
    - If there is only one consumer, that consumer will receive data from **all the partitions**. Kafka will handle delivering all the messages to the single consumer, regardless of partitioning.
- **Multiple Consumers**:
    - If there are multiple consumers, Kafka will perform **auto-balancing**, where the partitions are distributed among the consumers:
        - For example, with two consumers, Kafka may route data from Partitions 1 and 2 to the first consumer, and data from Partitions 3 and 4 to the second.
- **Partition-Consumer Relationship**:
    - **Important Rule**: A **partition** can only be consumed by one consumer at a time, ensuring that data is not duplicated or shared between consumers.
    - If there are **more partitions than consumers**, each consumer may receive data from multiple partitions.
    - Conversely, if there are **more consumers than partitions**, the extra consumers will remain **idle**, as Kafka can only distribute data that exists within the available partitions.
- **Database Usage**:
    - In real-world scenarios, each consumer could represent a different **database** or **service** that processes the partitioned data.
    - For example, Consumer 1 (Database 1) handles the North and South data, while Consumer 2 (Database 2) processes East and West data.
    - If there are more consumers (or databases) than available partitions, the extra consumers will sit idle, waiting for partitions to be assigned.

