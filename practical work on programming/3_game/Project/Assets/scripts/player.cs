using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class player : MonoBehaviour
{
    public float speed = 3f;
    void Update()
    {
        float InputX = Input.GetAxisRaw("Horizontal");

        Vector3 dir = new Vector3(InputX, 0, 0);
        transform.Translate(dir.normalized * Time.deltaTime * speed);
    }

    void OnCollisionStay(Collision collision)
    {
        if (collision.gameObject.CompareTag("Car"))
        {
            Destroy(gameObject);
        }
    }
}
