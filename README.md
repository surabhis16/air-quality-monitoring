
# Air Quality Forecasting and Monitoring System

This project aims to forecast air quality metrics using historical data and provide real-time monitoring via a web-based platform. By leveraging machine learning and time series analysis techniques, such as ARIMA, this system can predict future air quality levels and visualize pollutant concentrations, helping in air quality management and health monitoring.

## Project Overview

The project processes and analyzes air quality data collected from various sensors (including Arduino-based sensors) to predict pollutant concentrations. The focus is primarily on CO(GT) and NO2(GT) levels, which are key indicators of air pollution.

Key features of this project include:
- Data cleaning and preprocessing for accurate analysis.
- Statistical analysis and visualizations to explore pollutant trends.
- Machine learning-based forecasting using ARIMA.
- Real-time data visualization on ThingSpeak, providing continuous monitoring of air quality.
- Integration with Arduino-based sensors for real-time air quality data collection.

## Data Collection

The dataset used in this project is sourced from the [Air Quality UCI Dataset](https://archive.ics.uci.edu/ml/datasets/air+quality). It contains various pollutant measurements like CO, NO2, O3, and others, recorded over a period of time. Each data point includes the following features:
- **Date**: Date of the reading.
- **Time**: Time of the reading.
- **Pollutant levels**: CO(GT), NO2(GT), etc.
  
Missing values and invalid data are handled efficiently to ensure robust analysis.

### Arduino Integration
In addition to historical data, the system is equipped with an **Arduino-based sensor setup** to collect real-time air quality data. The Arduino, equipped with sensors like the **MQ-7** for CO and the **MQ-135** for NO2, sends real-time pollutant readings to a cloud platform (ThingSpeak). The system uses the data from these sensors to continuously monitor the air quality and send updates.

---

## Key Steps and Methodology

### 1. Data Cleaning and Preprocessing
- Missing data is replaced with a default value (-200) to indicate missing readings.
- Non-numeric rows are filtered out.
- Date and time columns are combined and converted to a proper datetime format.
- The dataset is normalized using MinMaxScaler to ensure consistency in measurement units.

### 2. Exploratory Data Analysis (EDA)
Various statistical techniques are employed to explore pollutant distributions, correlations, and temporal trends. Visualizations such as histograms, correlation heatmaps, and time-series plots are used to identify patterns and anomalies in the data.

### 3. Forecasting with ARIMA
- The ARIMA (AutoRegressive Integrated Moving Average) model is used to predict future air quality levels, specifically focusing on CO(GT) concentration.
- The time series data is decomposed to extract trends, seasonality, and residual components.
- First-order differencing is applied to make the time series stationary.
- ARIMA parameters (p, d, q) are optimized based on autocorrelation plots (ACF) and partial autocorrelation plots (PACF).

### 4. Model Evaluation
- The ARIMA model is trained using a training dataset, and predictions are made for a test set.
- Model performance is evaluated using metrics such as Mean Squared Error (MSE) and R-squared.

### 5. Integration with ThingSpeak
- Real-time air quality data is sent to ThingSpeak for continuous monitoring.
- ThingSpeak is used to create visual dashboards that display pollutant concentration in real time.
- The integration with ThingSpeak enables easy access to live data and enhances the visualization of trends.

## Real-Time Monitoring

The system is integrated with ThingSpeak, a cloud-based platform that facilitates the monitoring and visualization of sensor data. The air quality data is continuously uploaded to ThingSpeak, where it can be visualized in real-time. This allows for:
- Monitoring air quality in different locations.
- Analyzing trends and patterns in real-time data.
- Alerting authorities in case of abnormal pollutant levels.

### Arduino Integration for Real-Time Monitoring
- The **Arduino setup** transmits data from sensors (CO, NO2) to ThingSpeak via an **ESP8266 Wi-Fi module**.
- **Real-time updates** from Arduino-based sensors are reflected on ThingSpeak dashboards, which visualize pollutant concentration over time.
- This integration ensures that air quality monitoring is not only based on historical data but is also continuously updated with live sensor readings.

---

## Installation

1. **Clone the repository**:
   ```bash
   git clone https://github.com/yourusername/air-quality-forecasting.git
   cd air-quality-forecasting
   ```

2. **Install dependencies**:
   Ensure you have Python 3.7+ installed. Then, install the required libraries:
   ```bash
   pip install -r requirements.txt
   ```

3. **Data Setup**:
   Download the dataset from the [Air Quality UCI Dataset](https://archive.ics.uci.edu/ml/datasets/air+quality) and place it in the appropriate directory.

4. **Run the Jupyter Notebook**:
   Open and execute the provided Jupyter notebook for data analysis and model training.

5. **Arduino Setup**:
   - Assemble your **Arduino-based sensor setup** (MQ-7 for CO, MQ-135 for NO2).
   - Connect the sensors to an **ESP8266 Wi-Fi module** for wireless transmission.
   - Upload the Arduino code to send sensor data to ThingSpeak.

---

## Visualization

Various types of visualizations are used throughout the project to provide insights into air quality trends and model performance:
- **Distribution Plots**: To visualize the distribution of pollutant concentrations.
- **Correlation Heatmap**: To explore the relationships between different pollutants.
- **Time Series Plots**: To analyze pollutant levels over time and track trends.
- **Model Performance Plots**: To compare actual vs. predicted values.
- **ThingSpeak Dashboards**: To visualize real-time air quality data from Arduino sensors.

## Forecasting

The ARIMA model forecasts pollutant concentrations (specifically CO(GT) levels) for the next 30 days. This is done by training the model on historical data and using it to predict future values. The results are then plotted alongside actual values for comparison.

## Future Work

- **Real-Time Forecasting**: Extend the model to provide real-time forecasting based on live data from sensors.
- **Additional Pollutants**: Expand the forecasting capabilities to other pollutants like NO2 and O3.
- **Model Improvement**: Use more advanced models like LSTM or Prophet to improve prediction accuracy.
- **Integration with More IoT Devices**: Incorporate other IoT devices for more comprehensive monitoring.

## Conclusion

This project provides a comprehensive solution for air quality monitoring and forecasting. By using statistical methods and machine learning models, it allows for the prediction of pollutant levels and helps in real-time monitoring via ThingSpeak. The Arduino integration adds a practical layer to the system, enabling real-time data collection and visualization. This can play a significant role in urban planning, public health, and environmental sustainability efforts.

## Technologies Used

- **Data Processing**: Python, Pandas, NumPy
- **Data Visualization**: Matplotlib, Seaborn
- **Time Series Analysis**: ARIMA, Statsmodels
- **Real-time Monitoring**: ThingSpeak, IoT (Arduino, ESP8266)
- **Machine Learning**: Scikit-learn

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

--- 
