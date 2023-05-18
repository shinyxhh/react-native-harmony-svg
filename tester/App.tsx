/* eslint-disable react-native/no-inline-styles */
import React from 'react';
import {StyleSheet, View} from 'react-native';
import Svg, {Path, G} from 'react-native-svg';
import {Tester, TestSuite, TestCase} from '@rnoh/testerino';

const TRIANGLE_PATH_DATA = 'M90 0 L0 180 L180 180 Z';

function App({}): JSX.Element {
  return (
    <View style={styles.container}>
      <Tester>
        <TestSuite name="react-native-svg">
          <TestCase itShould="display black triangle">
            <Svg style={styles.svgContainer}>
              <Path d={TRIANGLE_PATH_DATA} />
            </Svg>
          </TestCase>
          <TestCase itShould="display red triangle with green border on blue background">
            <Svg style={[styles.svgContainer, {backgroundColor: 'blue'}]}>
              <Path
                d={TRIANGLE_PATH_DATA}
                fill="red"
                stroke="green"
                strokeWidth={8}
              />
            </Svg>
          </TestCase>
          <TestCase itShould="display right triangle larger compared to the left one">
            <View style={[styles.svgContainer, {flexDirection: 'row'}]}>
              <Svg style={{width: '50%', backgroundColor: 'red'}}>
                <Path d={TRIANGLE_PATH_DATA} />
              </Svg>
              <Svg
                style={{width: '50%', backgroundColor: 'green'}}
                viewBox="0 0 100 100">
                <Path d={TRIANGLE_PATH_DATA} />
              </Svg>
            </View>
          </TestCase>
          <TestCase itShould="[FAILS] display red rectangle with green border (G)">
            <Svg style={styles.svgContainer}>
              <G fill="red" stroke="green" strokeWidth={8}>
                <Path d={TRIANGLE_PATH_DATA} />
              </G>
            </Svg>
          </TestCase>
        </TestSuite>
      </Tester>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    width: '100%',
    height: '100%',
  },
  svgContainer: {
    width: '100%',
    height: 100,
  },
});

export default App;
