# Air Quality Forecasting and Monitoring System

This project forecasts air quality metrics using historical data and provides real-time monitoring through a web-based platform. By leveraging machine learning and time series analysis (ARIMA), it predicts future air quality levels and visualizes pollutant concentrations for better air quality management.

## Project Overview

The system processes air quality data from sensors (including Arduino-based) to predict pollutant concentrations. Focus areas include CO(GT) and NO2(GT) levels.

Key features:
- Data cleaning and preprocessing for accurate analysis.
- ARIMA-based forecasting for CO(GT) levels.
- Real-time visualization via ThingSpeak.
- Integration with Arduino-based sensors for real-time data collection.

## Data Collection

The dataset is sourced from the [Air Quality UCI Dataset](https://archive.ics.uci.edu/ml/datasets/air+quality). It includes measurements of various pollutants (CO, NO2, O3) over time, along with their respective timestamps.

### Arduino Integration
Arduino sensors (MQ-7 for CO, MQ-135 for NO2) send real-time data to ThingSpeak for continuous monitoring of air quality.

---

## Key Steps and Methodology

### 1. Data Cleaning
- Missing values replaced with -200.
- Non-numeric rows are removed.
- Data is normalized using MinMaxScaler.

### 2. Exploratory Data Analysis (EDA)
Statistical techniques and visualizations (e.g., histograms, time-series plots) are used to explore pollutant trends and correlations.

### 3. Forecasting with ARIMA
- ARIMA is used to predict future CO(GT) levels.
- Time series data is decomposed and differenced to make it stationary.
- ARIMA parameters (p, d, q) are optimized based on ACF and PACF plots.

### 4. Model Evaluation
Model performance is assessed using Mean Squared Error (MSE) and R-squared on the test data.

### 5. Integration with ThingSpeak
- Real-time data from sensors is uploaded to ThingSpeak for continuous monitoring and visualization.
- ThingSpeak provides dashboards to view pollutant levels in real-time.

## Real-Time Monitoring

The system uses ThingSpeak to monitor and visualize air quality data in real-time. It:
- Monitors air quality in various locations.
- Analyzes real-time data trends.
- Alerts authorities if pollutant levels exceed safe thresholds.

### Arduino Integration for Real-Time Monitoring
Arduino-based sensors send data to ThingSpeak through an ESP8266 module, enabling real-time updates and visualizations.

---

## Installation

1. **Clone the repository**:
   ```bash
   git clone https://github.com/yourusername/air-quality-forecasting.git
   cd air-quality-forecasting
   ```

2. **Install dependencies**:
   ```bash
   pip install -r requirements.txt
   ```

3. **Data Setup**:
   Download the dataset and place it in the required directory.

4. **Run the Jupyter Notebook** for analysis and model training.

5. **Arduino Setup**:
   - Connect sensors to the ESP8266 Wi-Fi module.
   - Upload Arduino code to send data to ThingSpeak.

---

## Visualization

Visualizations include:
- **Distribution Plots**: For pollutant concentrations.
- **Correlation Heatmap**: To explore pollutant relationships.
- **Time Series Plots**: To analyze pollutant trends.
- **Model Performance Plots**: To compare actual vs. predicted values.
- **ThingSpeak Dashboards**: For real-time data visualization.

## Forecasting

The ARIMA model predicts CO(GT) levels for the next 30 days, with comparisons between actual and forecasted values.

## Future Work

- **Real-Time Forecasting**: Extend to real-time predictions based on live data.
- **Additional Pollutants**: Forecast NO2 and O3 levels.
- **Model Improvement**: Explore LSTM or Prophet for better accuracy.
- **IoT Device Integration**: Incorporate other devices for comprehensive monitoring.

## Conclusion

This project offers a robust solution for air quality forecasting and real-time monitoring. Through machine learning and IoT integration, it aids in predicting and visualizing pollutant levels, contributing to better environmental health monitoring.

## Technologies Used

- **Data Processing**: Python, Pandas, NumPy
- **Data Visualization**: Matplotlib, Seaborn
- **Time Series Analysis**: ARIMA, Statsmodels
- **Real-time Monitoring**: ThingSpeak, IoT (Arduino, ESP8266)
- **Machine Learning**: Scikit-learn

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
```
