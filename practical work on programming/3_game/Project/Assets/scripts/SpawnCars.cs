using UnityEngine;
using System.Collections;

public class SpawnCars : MonoBehaviour
{
    public GameObject[] cars;
    private float[] positions = { 3.1f, 0, -3.1f };

    void Start()
    {
        StartCoroutine(spawn());
    }
    IEnumerator spawn()
    {
        while (true)
        {
            Instantiate(cars[Random.Range(0, cars.Length)],
                new Vector3(positions[Random.Range(0, 3)], 9f, 0),
                Quaternion.Euler(new Vector3(90, 180, 0)));
            yield return new WaitForSeconds(2.5f);
        }
    }
}
