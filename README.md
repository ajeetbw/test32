# Sprint Call Data Record Processor
## Overview
The Sprint Call Data Record (CDR) Processor is a comprehensive solution designed to handle CDR files that contain charging event records for cellular service providers. This project aims to provide a robust and efficient way to process CDR files, facilitating offline charging, customer billing, and inter-operator settlement.

## Description
The CDR Processor is built to manage large CDR files (1-5 MB) that contain descriptions of charging events such as voice calls and SMS messages. Each CDR record is composed of several fields, including MSISDN, Operator Brand Name, Operator MMC/MNC, Call Type, Duration, Download, Upload, Third Party MSISDN, and Third Party Operator MMC/MNC. The processor reads and processes these files to fulfill two primary functions: Customer Billing and Inter Operator Settlement.

## Technical Stack
### Languages and Frameworks
* **Programming Language:** Java
* **Framework:** Spring Boot
* **Libraries:**
	+ Apache Commons for file processing
	+ Jackson for JSON serialization and deserialization

### Technology Highlights
* **Database:** MySQL for storing processed CDR records
* **Operating System:** Linux/Unix-based systems for optimal performance

## Installation and Startup
### Prerequisites
* Java 11 or later
* Maven 3.6 or later
* MySQL 8.0 or later

### Steps to Install and Run
1. Clone the repository using `git clone`
2. Navigate to the project directory and run `mvn clean install` to build the project
3. Create a MySQL database and update the `application.properties` file with the database credentials
4. Run the application using `mvn spring-boot:run`
5. The application will start on port 8080 by default

## Usage
### API Endpoints
* **POST /process-cdr**: Process a CDR file and store the records in the database
* **GET /customer-billing**: Retrieve customer billing information
* **GET /inter-operator-settlement**: Retrieve inter-operator settlement information

### Example Requests
* **Process CDR File:**
```bash
curl -X POST \
  http://localhost:8080/process-cdr \
  -H 'Content-Type: application/json' \
  -d '{"cdrFile": "path/to/cdr/file"}'
```
* **Retrieve Customer Billing Information:**
```bash
curl -X GET \
  http://localhost:8080/customer-billing \
  -H 'Content-Type: application/json'
```

## Contributing
Contributions are welcome and appreciated. To contribute, please fork the repository, make the necessary changes, and submit a pull request. Ensure that all changes are properly tested and documented.

## Licensing
The Sprint Call Data Record Processor is licensed under the [Apache License 2.0](https://www.apache.org/licenses/LICENSE-2.0). By contributing to this project, you agree to release your contributions under this license.